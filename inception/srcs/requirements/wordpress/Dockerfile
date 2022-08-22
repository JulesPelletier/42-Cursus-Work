FROM    debian:buster

## Installing basic packages
RUN     apt update -y && apt upgrade -y 
RUN     apt-get install wget -y
RUN     apt-get install php7.3 -y
RUN     apt-get install php-fpm -y
RUN     apt-get install php-mysql -y
RUN     apt install vim -y
RUN     apt install curl -y

## Download WordPress
RUN     wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN     cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN		chown -R root:root /var/www/wordpress

## Setting up PHP
COPY    conf/www.conf /etc/php7.3/php-fpm.d/www.conf

## Adding script to start WordPress
COPY    tools/start-wp.sh   /tmp/start-wp.sh

## Setting up WordPress
RUN     wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN     chmod +x wp-cli.phar
RUN     mv wp-cli.phar /usr/local/bin/wp

EXPOSE  9000

ENTRYPOINT  ["sh" , "/tmp/start-wp.sh"]