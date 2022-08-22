FROM    debian:buster

## Installing basic packages
RUN     apt update -y && apt upgrade -y 
RUN     apt-get install nginx -y
RUN     apt install vim -y
RUN     apt install curl -y

## Setting up SSL cetrificate
RUN     mkdir -p /etc/nginx/ssl
RUN     apt-get install openssl -y
RUN     openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt          \
        -keyout /etc/nginx/ssl/inception.key -subj                          \
        "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=julpelle.42.fr/UID=julpelle"

## Setting up NGINX
RUN     mkdir -p /var/run/nginx
COPY    conf/nginx.conf     /etc/nginx/nginx.conf
RUN     chmod 775 /var/www/html
RUN     chown -R www-data:www-data /var/www/html

EXPOSE  443

CMD     [ "nginx" , "-g" , "daemon off;" ]