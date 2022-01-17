# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:14:53 by julpelle          #+#    #+#              #
#    Updated: 2022/01/17 20:44:59 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	account

SRCS 	=	srcs/main.cpp		\
			srcs/Account.cpp	\

OBJS 	=	$(SRCS:.cpp=.o)

CXX 	= 	clang++

CXXFLAGS =	-Wall -Wextra -Werror

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