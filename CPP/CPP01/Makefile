# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:14:53 by julpelle          #+#    #+#              #
#    Updated: 2022/01/11 18:26:11 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

SRCS		=	megaphone.cpp

OBJS		=	$(SRCS:.cpp=.o)

FLAGS		=	-Wall -Werror -Wextra

$(NAME):		$(OBJS)
				@clang++ $(FLAGS) -o $(NAME) $(OBJS)

all:			$(NAME)

clean:			@echo "Cleaning : $(OBJS)"
				@rm -rf $(OBJS)

fclean:			clean
				@echo "Cleaning : $(NAME)"
				@rm -rf $(NAME)

re:				fclean all