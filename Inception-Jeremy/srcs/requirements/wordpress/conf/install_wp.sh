#!/bin/bash

cd /var/www/html

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root --locale=en_AU
wp config create --allow-root --dbhost=mariadb --dbname=${MYSQL_DB} --dbuser=${MYSQL_WP_USER} --dbpass=$(cat /run/secrets/wp_db_pass)
wp db create --allow-root
wp core install --allow-root --url=${DOMAIN_NAME} --title="${WP_SITE_TITLE}" --admin_user=${WP_ADMIN} --admin_password=$(cat /run/secrets/wp_admin_pass) --admin_email=${WP_ADMIN_EMAIL}

wp user create --allow-root ${WP_USER} ${WP_USER_EMAIL} --user_pass="$(cat /run/secrets/wp_user_pass)"
wp option update siteurl https://${DOMAIN_NAME} --allow-root
wp option update home https://${DOMAIN_NAME} --allow-root

php-fpm7.4 -F