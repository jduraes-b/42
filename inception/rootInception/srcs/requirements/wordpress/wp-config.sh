#!/bin/bash
set -euo pipefail

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] WordPress: $1"
}

error_exit() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] ERROR: $1" >&2
    exit 1
}

# Read secrets with error checking
MYSQL_USER=$(cat /run/secrets/mysql_user 2>/dev/null) || error_exit "Failed to read mysql_user secret"
MYSQL_PASSWORD=$(cat /run/secrets/mysql_password 2>/dev/null) || error_exit "Failed to read mysql_password secret"
WP_ADMIN_USER=$(cat /run/secrets/wp_admin_user 2>/dev/null) || error_exit "Failed to read wp_admin_user secret"
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_adminpassword 2>/dev/null) || error_exit "Failed to read wp_adminpassword secret"
WP_ADMIN_EMAIL=$(cat /run/secrets/wp_admin_mail 2>/dev/null) || error_exit "Failed to read wp_admin_mail secret"

# Validate required variables
[[ -z "$MYSQL_USER" ]] && error_exit "MySQL user is empty"
[[ -z "$MYSQL_PASSWORD" ]] && error_exit "MySQL password is empty"
[[ -z "$WP_ADMIN_USER" ]] && error_exit "WordPress admin user is empty"
[[ -z "$WP_ADMIN_PASSWORD" ]] && error_exit "WordPress admin password is empty"
[[ -z "$WP_ADMIN_EMAIL" ]] && error_exit "WordPress admin email is empty"

# Use environment variables for host, db name, url (still needed)
DB_HOST=${WORDPRESS_DB_HOST:-mariadb}
DB_NAME=${WORDPRESS_DB_NAME:-wordpress}
WP_URL=${WORDPRESS_URL}


# Wait for MariaDB with timeout
log "Waiting for MariaDB to be ready..."
timeout=60
counter=0
until (echo > /dev/tcp/$DB_HOST/3306) >/dev/null 2>&1; do
    counter=$((counter + 1))
    if [ $counter -ge $timeout ]; then
        error_exit "Timeout waiting for MariaDB to be ready"
    fi
    sleep 2
done
log "MariaDB is ready!"

# WordPress setup
if [ -f "/var/www/html/wp-config.php" ]; then
    log "WordPress already configured."
else
    log "Configuring WordPress..."
    cd /var/www/html || error_exit "Failed to change to /var/www/html directory"

    # Download WP-CLI with error handling (skip if already exists)
    if [ ! -f "wp-cli.phar" ]; then
        log "Downloading WP-CLI..."
        curl -s -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar || error_exit "Failed to download WP-CLI"
        chmod +x wp-cli.phar || error_exit "Failed to make WP-CLI executable"
    else
        log "WP-CLI already exists, skipping download"
    fi

    # Download WordPress (skip if already exists)
    if [ ! -f "index.php" ] || [ ! -f "wp-load.php" ]; then
        log "Downloading WordPress core..."
        ./wp-cli.phar core download --allow-root || error_exit "Failed to download WordPress"
    else
        log "WordPress core files already exist, skipping download"
    fi

    # Create wp-config.php only if it doesn't exist
    if [ ! -f "wp-config.php" ]; then
        log "Creating wp-config.php..."
        ./wp-cli.phar config create \
            --dbname="$DB_NAME" \
            --dbuser="$MYSQL_USER" \
            --dbpass="$MYSQL_PASSWORD" \
            --dbhost="$DB_HOST" \
            --allow-root || error_exit "Failed to create wp-config.php"
    else
        log "wp-config.php already exists, skipping creation"
    fi

    # Install WordPress only if not already installed
    if ! ./wp-cli.phar core is-installed --allow-root 2>/dev/null; then
        log "Installing WordPress..."
        ./wp-cli.phar core install \
            --url="$WP_URL" \
            --title="Inception" \
            --admin_user="$WP_ADMIN_USER" \
            --admin_password="$WP_ADMIN_PASSWORD" \
            --admin_email="$WP_ADMIN_EMAIL" \
            --skip-email \
            --allow-root || error_exit "Failed to install WordPress"
        
        # Create a regular user (non-admin) only after successful install
        log "Creating regular user..."
        ./wp-cli.phar user create regularuser user@example.com \
            --role=author \
            --user_pass="regularpass123" \
            --allow-root || log "Warning: Failed to create regular user (may already exist)"
    else
        log "WordPress is already installed, skipping installation"
    fi
    
    echo "WordPress setup completed!"
fi

# Start PHP-FPM
exec php-fpm8.2 -F
