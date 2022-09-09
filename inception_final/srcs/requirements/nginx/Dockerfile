FROM	debian:buster

## Updating apt-get
RUN		apt-get -y update

## Installing packages
RUN		apt-get -y install nginx 
RUN		apt-get -y install openssl

## Copying config file
COPY 	./config/nginx.conf /etc/nginx/nginx.conf

## Creating SSL certificate
RUN 	openssl req -newkey rsa:4096 -x509 -sha3-256 -days 365 -nodes			\
		-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=Student Projects/CN=inception"	\
		-out /etc/ssl/certs/server.crt -keyout /etc/ssl/private/server.key

## Start NGINX
CMD	[ "nginx", "-g", "daemon off;" ]