# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 12:43:22 by julpelle          #+#    #+#              #
#    Updated: 2021/12/06 06:39:14 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo

SRCS 	=	srcs/utils/ft_atoi.c				\
			srcs/utils/get_chrono.c				\
			srcs/utils/ft_putstr_fd.c			\
			srcs/utils/ft_putchar_fd.c			\
			srcs/utils/ft_exit.c				\
			srcs/init/init.c					\
			srcs/parsing/parsing.c				\
			srcs/parsing/check_args.c			\
			srcs/loop/routine.c					\
			srcs/loop/thread.c					\
			srcs/loop/check_threads.c			\
			srcs/loop/free.c					\
			srcs/main.c							\

OBJS 	= 	$(SRCS:.c=.o)

RM		= 	rm -rf

CC 		= 	clang

FLAGS 	= 	-Wall -Wextra -Werror -pthread #-fsanitize=thread -g3

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(FLAGS) $^ -o $@

%.o:		%.c
				$(CC) $(FLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY: 	clean fclean re
