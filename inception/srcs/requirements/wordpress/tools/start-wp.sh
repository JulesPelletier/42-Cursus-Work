#!/bin/sh

sleep 10
if [ ! -d /var/www/html/wordpress ]
then
	mkdir /var/www/html/wordpress
	cd /var/www/html/wordpress
	wp config create	--allow-root \
    					--dbname=$MYSQL_DATABASE \
    					--dbuser=$MYSQL_USER \
    					--dbpass=$MYSQL_USER_PWD \
    					--dbhost=mariadb:3306 --path='/var/www/html/wordpress'
	wp core install --url=julpelle.42.fr --title=julpelle_website --admin_user=$WP_USER --admin_password=$MYSQL_ROOT_PWD --admin_email=julespelletier.perso@gmail.com
	wp user create correcteur correcteur@test.fr --user_pass=$WP_PWD
fi

/usr/sbin/php-fpm7.3 -F -R