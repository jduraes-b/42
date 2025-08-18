#!/bin/bash
# Custom MariaDB initialization script
# This script is run by Docker entrypoint to set up additional users or databases

echo "Running custom MariaDB init scripts..."
# Example: create a backup user
# mysql -uroot -prootpassword -e "CREATE USER 'backup'@'%' IDENTIFIED BY 'backup'; GRANT SELECT ON *.* TO 'backup'@'%';"
