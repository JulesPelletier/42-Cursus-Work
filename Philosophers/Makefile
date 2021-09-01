# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:33:15 by Jules             #+#    #+#              #
#    Updated: 2021/08/31 16:08:47 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILOSOPHER	 		=	philo

CC 					=	gcc

CFLAGS 				=	-Wall -Wextra -Werror -fsanitize=address

INCDIRS				=	-Iincludes


SRCS_PHILO	 		=	srcs/ft_atoi.c					\
						srcs/init_struct.c				\
						srcs/main.c						\
						srcs/utils.c					\

OBJS_PHILO			=	$(SRCS_PHILO:.c=.o)

all:					$(OBJS_PHILO) $(PHILOSOPHER)

$(PHILOSOPHER):			$(OBJS_PHILO) 
						$(CC) $(CFLAGS) $(OBJS_PHILO) -o $@ 


%.o:					%.c
						$(CC)  $(INCDIRS) -o $@ -c $?


clean:
						rm -f $(OBS_PHILO)

fclean:					clean
						rm -f $(PHILOSOPHER)

re:						fclean all

.PHONY: 				all, $(PHILOSOPHER), clean, fclean, re