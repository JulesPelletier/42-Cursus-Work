# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:33:15 by Jules             #+#    #+#              #
#    Updated: 2021/12/05 16:59:10 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILOSOPHER	 		=	philo

CC 					=	gcc

CFLAGS 				=	-Wall -Wextra -Werror -fsanitize=address -g3 -ggdb

INCDIRS				=	-Iincludes

LIBS				=	-lpthread


SRCS_PHILO	 		=	srcs/functions/ft_atoi.c					\
						srcs/functions/ft_isdigit.c					\
						srcs/functions/ft_strlen.c					\
						srcs/functions/ft_putchar_fd.c				\
						srcs/functions/ft_putstr_fd.c				\
						srcs/functions/ft_putnbr_fd.c				\
						srcs/functions/ft_exit.c					\
						srcs/functions/ft_wait.c					\
						srcs/functions/get_chrono.c					\
						srcs/parsing/parse.c						\
						srcs/parsing/check_args.c					\
						srcs/loop/routine.c							\
						srcs/loop/actions.c							\
						srcs/loop/threading.c						\
						srcs/loop/timestamp.c						\
						srcs/loop/check_death.c						\
						srcs/loop/end_loop.c						\
						srcs/main.c									\
						srcs/show.c									\

OBJS_PHILO			=	$(SRCS_PHILO:.c=.o)

all:					$(OBJS_PHILO) $(PHILOSOPHER)

$(PHILOSOPHER):			$(OBJS_PHILO) 
						$(CC) $(CFLAGS) $(OBJS_PHILO) ${LIBS} -o $@ 


%.o:					%.c
						$(CC) $(CFLAGS) $(INCDIRS) -o $@ -c $?

clean:					
						rm -f $(OBJS_PHILO)

fclean:					clean
						rm -f $(PHILOSOPHER)

re:						fclean all

.PHONY: 				all, $(PHILOSOPHER), clean, fclean, re