FROM wordpress:latest

# Copy custom PHP configuration files
COPY conf/ /usr/local/etc/php/conf.d/

# Copy any helper scripts or utilities
COPY utils/ /usr/local/bin/
RUN chmod +x /usr/local/bin/* || true

# Expose HTTP port
EXPOSE 80

# The official WordPress entrypoint will set up and launch the server