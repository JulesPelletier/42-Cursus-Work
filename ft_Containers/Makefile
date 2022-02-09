# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:51:28 by julpelle          #+#    #+#              #
#    Updated: 2022/02/09 01:48:32 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	container

SRCS 	=	srcs/main.cpp 						\
			srcs/tests/vector/TestVector.cpp		\

OBJS 	=	$(SRCS:.cpp=.o)

CXX 	= 	clang++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

RM 		=	rm -rf

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS) .vscode

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re