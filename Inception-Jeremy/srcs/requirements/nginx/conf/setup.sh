#!/bin/bash

mkdir -p /etc/ssl/localcerts/ \
    && openssl req -new -x509 -days 365 -nodes \
        -out /etc/ssl/localcerts/nginx.pem \
        -keyout /etc/ssl/localcerts/nginx.key \
        -subj "/CN=${DOMAIN_NAME}"

sed -i "s/repl_server_name/${DOMAIN_NAME}/" /etc/nginx/sites-enabled/default

nginx -g "daemon off;"