# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:51:28 by julpelle          #+#    #+#              #
#    Updated: 2022/02/26 01:26:51 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brain

SRCS 	=	srcs/main.cpp 		\
			srcs/Animal.cpp 		\
			srcs/WrongAnimal.cpp 		\
			srcs/Dog.cpp 		\
			srcs/Cat.cpp 		\
			srcs/WrongCat.cpp 		\
			srcs/Brain.cpp 		\


OBJS 	=	$(SRCS:.cpp=.o)

CXX 	= 	clang++

CXXFLAGS =	--std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

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