FROM debian:bookworm

RUN apt update -y && apt install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/* && \
    apt clean

RUN mkdir -p /etc/nginx/certs && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/certs/nginx-selfsigned.key \
    -out /etc/nginx/certs/nginx-selfsigned.crt \
    -subj "/C=PT/ST=Porto/L=Porto/O=42Porto/OU=Cadet/CN=${DOMAIN_NAME}"

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default /etc/nginx/sites-available/default

RUN chmod 644 /etc/nginx/certs/nginx-selfsigned.key && \
    chmod 644 /etc/nginx/certs/nginx-selfsigned.crt && \
    chown -R www-data:www-data /var/log/nginx /var/lib/nginx /etc/nginx/certs
EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
