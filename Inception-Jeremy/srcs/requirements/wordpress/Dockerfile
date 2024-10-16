FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y \
    php-fpm \
    php-mysqli \
    curl

RUN mkdir -p /run/php/

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/.

COPY conf/install_wp.sh .
RUN chmod +x install_wp.sh

CMD ["./install_wp.sh"]