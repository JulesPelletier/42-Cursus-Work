# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:14:17 by julpelle          #+#    #+#              #
#    Updated: 2022/01/13 15:11:39 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

SRCS_DIR 	= ./

SRCS		=	megaphone.cpp

CXX			= calng++

OBJS_DIR 	= 	objects/

OBJ			=	$(SRCS:.cpp=.o)

OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))

CXXFLAGS	=	-Wall -Werror -Wextra

$(NAME):		$(OBJS)
				$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

all:			$(NAME)

clean:			@echo "Cleaning : $(OBJS_DIR)"
				@rm -rf $(OBJS_DIR)

fclean:			clean
				@echo "Cleaning : $(NAME)"
				@rm -rf $(NAME)

re:				fclean all