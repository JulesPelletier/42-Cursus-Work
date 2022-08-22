# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:33:40 by julpelle          #+#    #+#              #
#    Updated: 2022/07/21 13:26:05 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH	=	srcs/docker-compose.yaml

all		:	build files up
			docker-compose -f $(PATH) up --build -d

build	:	
			docker-compose -f $(PATH) build

files	:	
			mkdir	/home/julpelle/data/wordpress
			mkdir	/home/julpelle/data/mariadb

clean	:
			docker-compose -f $(PATH) down --volumes
			rm -rf	/home/julpelle/data/wordpress
			rm -rf	/home/julpelle/data/mariadb

fclean	:	clean

up		:	
			docker-compose -f $(PATH) up

down	:
			docker-compose -f $(PATH) down

re		:	rm build
			docker-compose -f $(PATH) up 