FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y \
    mariadb-server

RUN mkdir -p /run/mysqld

RUN mariadb-install-db --user=${MYSQL_ROOT_USER}

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/.

COPY conf/setup_wordpress.sh .
RUN chmod +x setup_wordpress.sh

CMD ["./setup_wordpress.sh"]