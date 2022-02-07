# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:51:28 by julpelle          #+#    #+#              #
#    Updated: 2022/02/07 19:56:07 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bureaucrat

SRCS 	=	srcs/main.cpp 		\
			srcs/Bureaucrat.cpp		\
			srcs/Form.cpp		\
			srcs/ShrubberyCreationForm.cpp		\
			srcs/PresidentialPardonForm.cpp		\
			srcs/RobotomyRequestForm.cpp		\
			srcs/Intern.cpp		\

OBJS 	=	$(SRCS:.cpp=.o)

CXX 	= 	clang++

CXXFLAGS =	-Wall -Wextra -Werror -fsanitize=address -g3

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