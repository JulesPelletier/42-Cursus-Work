# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:33:15 by Jules             #+#    #+#              #
#    Updated: 2021/12/04 18:51:15 by julpelle         ###   ########.fr        #
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
						srcs/init/init_struct.c						\
						srcs/parsing/check_params.c					\
						srcs/main.c									\
						srcs/algo/timestamp.c 						\
						srcs/algo/checks.c 						\
						srcs/algo/loop.c 						\
						srcs/algo/loop_functions.c 						\
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