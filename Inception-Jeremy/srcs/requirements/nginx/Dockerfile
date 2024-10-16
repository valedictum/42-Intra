
FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y \
    nginx openssl

COPY conf/default /etc/nginx/sites-enabled/.
COPY conf/setup.sh .
RUN chmod +x setup.sh

CMD ["./setup.sh"]
