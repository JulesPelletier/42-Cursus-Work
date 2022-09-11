# setting the OS
FROM	debian:buster

# update apt-get
RUN 	apt-get -y update

# installing mariadb
RUN 	apt-get -y install mariadb-server mariadb-client && \
		mkdir -p /run/mysqld/; mkdir -p  /var/run/mysqld/ && \
		chown -R mysql:root /run/mysqld ; chown -R mysql:root /var/run/mysqld/

# set up mariadb
COPY 	./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY 	./script.sh /root/script.sh

# script to launch mariadb,  create users and DB
ENTRYPOINT bash /root/script.sh
