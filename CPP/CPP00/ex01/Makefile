# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:14:17 by julpelle          #+#    #+#              #
#    Updated: 2022/01/14 15:05:31 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRCS 	=	srcs/PhoneBook.cpp	\
			srcs/Contact.cpp	\
			srcs/main.cpp

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