#!/bin/bash

touch /etc/mysql/init.sql
echo "CREATE DATABASE ${MYSQL_DB};" >> /etc/mysql/init.sql
echo "CREATE USER '${MYSQL_WP_USER}'@'%' IDENTIFIED BY '$(cat /run/secrets/wp_db_pass)';" >> /etc/mysql/init.sql
echo "GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_WP_USER}'@'%' WITH GRANT OPTION;" >> /etc/mysql/init.sql
echo "FLUSH PRIVILEGES;" >> /etc/mysql/init.sql

mysqld