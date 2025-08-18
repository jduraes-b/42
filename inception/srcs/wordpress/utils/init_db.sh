#!/bin/bash
# Helper script to initialize WordPress DB or perform migrations
# Wait for MariaDB to be ready
until mysqladmin ping -hmariadb --silent; do
  sleep 1
done

# You can run custom SQL here, for example creating extra tables or seeding data
# mysql -hmariadb -uwp_user -pwp_password wordpress < /path/to/init.sql

echo "WordPress DB is ready."
