FROM	debian:buster

## Updating apt-get
RUN     apt-get -y update

## Installing packages
RUN     apt-get -y install php7.3 
RUN     apt-get -y install php7.3-fpm 
RUN     apt-get -y install php7.3-mysql 
RUN     apt-get -y install php-common
RUN     apt-get -y install curl 
RUN     apt-get -y install mariadb-client

## Copying config file
COPY    ./config/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY    ./tools/start_wp.sh .


## Creating PHP directory
RUN     mkdir -p /run/php

## Setting up WORDPRESS
RUN     curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN     chmod +x wp-cli.phar
RUN     mv wp-cli.phar /usr/local/bin/wp

## Start WORDPRESS
CMD     bash start_wp.sh && php-fpm7.3 -F -R