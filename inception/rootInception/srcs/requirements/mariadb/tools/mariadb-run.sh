#!/bin/bash
set -euo pipefail

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] MariaDB: $1"
}

error_exit() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] ERROR: $1" >&2
    exit 1
}

# Read secrets with error checking
SQL_USER=$(cat /run/secrets/mysql_user 2>/dev/null) || error_exit "Failed to read mysql_user secret"
SQL_PASS=$(cat /run/secrets/mysql_password 2>/dev/null) || error_exit "Failed to read mysql_password secret"  
SQL_ROOT_PASS=$(cat /run/secrets/mysql_rootpassword 2>/dev/null) || error_exit "Failed to read mysql_rootpassword secret"

# Validate required variables
[[ -z "$SQL_USER" ]] && error_exit "MySQL user is empty"
[[ -z "$SQL_PASS" ]] && error_exit "MySQL password is empty"
[[ -z "$SQL_ROOT_PASS" ]] && error_exit "MySQL root password is empty"

MYSQL_DATABASE="wordpress"

log "Preparing MariaDB..."
log "Database: $MYSQL_DATABASE"
log "User: $SQL_USER"

# Ensure directories exist and have correct permissions
mkdir -p /var/run/mysqld /var/lib/mysql /var/log/mysql || error_exit "Failed to create directories"
chown -R mysql:mysql /var/run/mysqld /var/lib/mysql /var/log/mysql || error_exit "Failed to set directory permissions"

# Change to mysql user for database operations if running as root
if [ "$(id -u)" = "0" ]; then
    log "Running as root, will use mysql user for database operations"
    DB_USER="mysql"
else
    log "Running as $(whoami)"
    DB_USER="$(whoami)"
fi

# init database if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    log "First init detected. Installing database..."
    mysql_install_db --user=$DB_USER --datadir=/var/lib/mysql || error_exit "Failed to install database"
    NEED_CONFIG=true
else
    log "MariaDB system database already exists."
    NEED_CONFIG=false
fi

# Start MariaDB temporarily to check/create WordPress user
log "Starting temporary MariaDB for configuration..."
mysqld --user=$DB_USER --skip-networking --socket=/tmp/mysql_init.sock &
MYSQL_PID=$!

# Wait for MariaDB to be ready
sleep 5

# Check if WordPress user exists by counting matching users
USER_COUNT=$(mysql -S /tmp/mysql_init.sock -u root -p"$SQL_ROOT_PASS" -s -N -e "SELECT COUNT(*) FROM mysql.user WHERE User='${SQL_USER}';" 2>/dev/null || \
             mysql -S /tmp/mysql_init.sock -u root -s -N -e "SELECT COUNT(*) FROM mysql.user WHERE User='${SQL_USER}';" 2>/dev/null || echo "0")

if [ "$USER_COUNT" -eq 0 ]; then
    log "WordPress user not found. Creating user and database..."
    
    tempfile=$(mktemp) || error_exit "Failed to create temp file"
    cat > "$tempfile" <<-EOF
USE mysql;
FLUSH PRIVILEGES;
-- Try to set root password (may fail if already set)
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASS}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASS}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '${SQL_ROOT_PASS}' WITH GRANT OPTION;
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
FLUSH PRIVILEGES;
EOF
    
    # Try with password first, then without
    mysql -S /tmp/mysql_init.sock -u root -p"$SQL_ROOT_PASS" < "$tempfile" 2>/dev/null || \
    mysql -S /tmp/mysql_init.sock -u root < "$tempfile" || error_exit "Failed to configure database"
    rm -f "$tempfile" || log "Warning: Failed to remove temp file"
    
    log "Database configuration done!"
    log "Created database: $MYSQL_DATABASE"
    log "Created user: $SQL_USER"
else
    log "WordPress user already exists. Skipping user creation."
fi

# Stop temporary MariaDB
kill $MYSQL_PID
wait $MYSQL_PID 2>/dev/null || true
rm -f /tmp/mysql_init.sock

unset SQL_USER SQL_PASS SQL_ROOT_PASS

log "Starting MariaDB..."
exec mysqld --user=$DB_USER --console

