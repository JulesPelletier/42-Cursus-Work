# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:51:28 by julpelle          #+#    #+#              #
#    Updated: 2022/02/26 01:25:45 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	diamondtrap

SRCS 	=	srcs/main.cpp 				\
			srcs/ClapTrap.cpp 			\
			srcs/ScavTrap.cpp 			\
			srcs/FragTrap.cpp 			\
			srcs/DiamondTrap.cpp 		\


OBJS 	=	$(SRCS:.cpp=.o)

CXX 	= 	clang++

CXXFLAGS =	--std=c++98 -Wall -Wextra -Werror -Wno-shadow

RM 		=	rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re