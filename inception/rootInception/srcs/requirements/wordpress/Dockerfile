FROM debian:bookworm

RUN apt update -y && apt install -y \
    php8.2-fpm \
    php8.2-mysqli \
    php8.2-curl \
    php8.2-gd \
    php8.2-mbstring \
    php8.2-xml \
    php8.2-zip \
    php8.2-intl \
    php8.2-bcmath \
    curl \
    && rm -rf /var/lib/apt/lists/* && \
    apt clean

RUN mkdir -p /run/php /var/www/html && \
    chown -R www-data:www-data /run/php /var/www/html

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY wp-config.sh /wp-config.sh
RUN chmod +x /wp-config.sh
EXPOSE 9000

ENTRYPOINT ["/wp-config.sh"]
