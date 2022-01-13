# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:14:17 by julpelle          #+#    #+#              #
#    Updated: 2022/01/13 15:44:17 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRCS 	=	PhoneBook.cpp

OBJS 	=	$(SRCS:.cpp=.o)

CC 		= 	clang++

CFLAGS 	=	-Wall -Wextra -Werror

RM 		=	rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re