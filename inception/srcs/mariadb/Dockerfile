FROM mariadb:latest

# Copy custom MariaDB configuration files
COPY conf/ /etc/mysql/conf.d/

# Copy initialization SQL scripts or utilities
COPY utils/ /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/* || true

# Expose MariaDB port
EXPOSE 3306

# The official image's entrypoint will initialize and start the database by default