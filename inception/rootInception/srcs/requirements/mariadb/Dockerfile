FROM debian:bookworm

RUN apt update -y && apt install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/* && \
    apt clean

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/mariadb-run.sh /mariadb-run.sh
RUN chmod +x /mariadb-run.sh && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql
EXPOSE 3306

ENTRYPOINT ["/mariadb-run.sh"]