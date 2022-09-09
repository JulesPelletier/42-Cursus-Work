# setting the OS
FROM	debian:buster

# setting the author
LABEL	julpelle <julpelle@student.42.fr>

# update apt-get
RUN apt-get -y update

# installing mariadb
RUN apt-get -y install mariadb-server 
RUN apt-get -y install mariadb-client
RUN	mkdir -p /run/mysqld/
RUN mkdir -p  /var/run/mysqld/
RUN	chown -R mysql:root /run/mysqld 
RUN	chown -R mysql:root /var/run/mysqld/

# set up mariadb
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./script.sh /root/script.sh

RUN		ln -sf /dev/stdout /var/log/mysql/mariadb.log	&& \
		ln -sf /dev/stderr /var/log/mysql/error.log

# script to launch mariadb,  create users and DB
ENTRYPOINT bash /root/script.sh
