# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:33:15 by Jules             #+#    #+#              #
#    Updated: 2021/09/07 17:55:23 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILOSOPHER	 		=	philo

CC 					=	gcc -fsanitize=address

CFLAGS 				=	-Wall -Wextra -Werror -fsanitize=address

INCDIRS				=	-Iincludes

LIBS				=	-lpthread


SRCS_PHILO	 		=	srcs/utils/ft_atoi.c					\
						srcs/utils/ft_isdigit.c					\
						srcs/utils/ft_strlen.c					\
						srcs/utils/ft_putchar_fd.c				\
						srcs/utils/ft_putnbr_fd.c				\
						srcs/init_struct.c						\
						srcs/check_params.c						\
						srcs/main.c								\
						srcs/functions.c						\
						srcs/functions2.c						\
						srcs/timestamp.c 						\
						srcs/thread.c 							\
						srcs/show.c								\

OBJS_PHILO			=	$(SRCS_PHILO:.c=.o)

all:					$(OBJS_PHILO) $(PHILOSOPHER)

$(PHILOSOPHER):			$(OBJS_PHILO) 
						$(CC) $(CFLAGS) $(OBJS_PHILO) ${LIBS} -o $@ 


%.o:					%.c
						$(CC)  $(INCDIRS) -o $@ -c $?

clean:					
						rm -f $(OBJS_PHILO)

fclean:					clean
						rm -f $(PHILOSOPHER)

re:						fclean all

.PHONY: 				all, $(PHILOSOPHER), clean, fclean, re