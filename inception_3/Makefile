NAME = inception

HOST_PRESENT = $(shell cat /etc/hosts | grep julpelle.42.fr > /dev/null; echo $$?)
all: 
ifneq ($(HOST_PRESENT), 0)
	@ sudo echo '127.0.0.1	julpelle.42.fr' | sudo tee -a /etc/hosts
	@ touch .first_launch
endif
	@ mkdir -p /home/julpelle/data/wp_files/
	@ mkdir -p /home/julpelle/data/db_files/
	@ docker-compose -f ./srcs/docker-compose.yml up -d --build

up:
	@ docker-compose -f ./srcs/docker-compose.yml up -d
	
down:
	@ docker-compose -f ./srcs/docker-compose.yml down

clean: down
	@ docker container prune; 

fclean: clean
	@ sudo rm -rf /home/julpelle/data/wp_files
	@ sudo rm -rf /home/julpelle/data/db_files
	@ docker system prune -a
	@ rm -f ".first_launch"



re: fclean all

 
.PHONY: up down clean fclean re all