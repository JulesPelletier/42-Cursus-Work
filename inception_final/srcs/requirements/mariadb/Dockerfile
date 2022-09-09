FROM	debian:buster

## Updating apt-get
RUN 	apt-get -y update

## Installing packages
RUN 	apt-get -y install mariadb-server 
RUN		apt-get -y install mariadb-client
RUN     mkdir -p /run/mysqld/; 
RUN		mkdir -p  /var/run/mysqld/
RUN		chown -R mysql:root /run/mysqld 
RUN		chown -R mysql:root /var/run/mysqld/

## Copying config and starting script files
COPY 	./config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY 	./tools/start_db.sh /root/start_db.sh

## Start MARIADB	
ENTRYPOINT bash /root/start_db.sh
