# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:33:15 by Jules             #+#    #+#              #
#    Updated: 2021/11/24 15:56:37 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILOSOPHER	 		=	philo

CC 					=	gcc

CFLAGS 				=	-Wall -Wextra -Werror -fsanitize=address -g3 -ggdb

INCDIRS				=	-Iincludes

LIBS				=	-lpthread


SRCS_PHILO	 		=	srcs/utils/ft_atoi.c					\
						srcs/utils/ft_isdigit.c					\
						srcs/utils/ft_strlen.c					\
						srcs/utils/ft_putchar_fd.c				\
						srcs/utils/ft_putstr_fd.c				\
						srcs/utils/ft_putnbr_fd.c				\
						srcs/utils/ft_exit.c					\
						srcs/init_struct.c						\
						srcs/check_params.c						\
						srcs/main.c								\
						srcs/loop.c								\
						srcs/functions.c						\
						srcs/timestamp.c 						\
						srcs/show.c								\

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