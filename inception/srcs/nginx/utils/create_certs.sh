#!/bin/bash
# Generate self-signed SSL certificates if they don't exist
if [ ! -f /etc/ssl/certs/nginx.crt ] || [ ! -f /etc/ssl/certs/nginx.key ]; then
  openssl req -x509 -nodes -days 365 \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost" \
    -newkey rsa:2048 \
    -keyout /etc/ssl/certs/nginx.key \
    -out /etc/ssl/certs/nginx.crt
fi

# Execute the passed command
exec "$@"
