FROM    debian:buster

## Installing basic packages
RUN     apt update -y && apt upgrade -y 
RUN     apt-get install mariadb-server -y
RUN     apt install vim -y
RUN     apt install curl -y

## Setting up MARIADB
COPY    config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

## Adding script to start  MariaDB
COPY    tools/start-db.sh   /tmp/start-db.sh

CMD     ["sh" , "/tmp/start-db.sh"]