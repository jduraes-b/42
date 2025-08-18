FROM nginx:alpine

# Install bash if you need scripting utilities
RUN apk add --no-cache bash openssl

# Remove default config and add custom conf files
RUN rm /etc/nginx/conf.d/default.conf
COPY conf/ /etc/nginx/conf.d/

# Copy any helper scripts or SSL utils
COPY utils/ /usr/local/bin/
RUN chmod +x /usr/local/bin/*

# Expose web ports
EXPOSE 80 443

# Run Nginx in foreground
CMD ["nginx", "-g", "daemon off;"]