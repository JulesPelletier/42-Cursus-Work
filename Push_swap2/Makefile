# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 15:10:36 by Jules             #+#    #+#              #
#    Updated: 2021/07/28 09:02:41 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP 		=	push_swap

CC 				=	gcc

CFLAGS 			=	-Wall -Wextra -Werror -g3 

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS_PUSH_SWAP 	=	GNL/get_next_line.c 					\
					GNL/get_next_line_utils.c				\
					srcs/push_swap/algo_quinze_plus.c		\
					srcs/push_swap/algo_quinze.c			\
					srcs/push_swap/algo_three.c				\
					srcs/push_swap/check_args.c				\
					srcs/push_swap/clean.c					\
					srcs/push_swap/errors.c					\
					srcs/push_swap/free.c					\
					srcs/push_swap/functions.c				\
					srcs/push_swap/functions2.c				\
					srcs/push_swap/functions3.c				\
					srcs/push_swap/init.c					\
					srcs/push_swap/median.c					\
					srcs/push_swap/operations_menu.c		\
					srcs/push_swap/opti.c					\
					srcs/push_swap/push_swap.c				\
					srcs/push_swap/read_arg.c				\
					srcs/push_swap/sorted.c					\

								
OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)

OBJS			=	$(SRCS:.c=.o)


all:				$(LIBFT_LIB) $(OBJS) $(PUSH_SWAP)

$(PUSH_SWAP):		$(OBJS_PUSH_SWAP) $(OBJS) $(LIBFT_LIB) 
					$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS) $(LIBFT_LIB) -o $@ 


%.o:				%.c
					$(CC) $(CFLAGS)  -I. -o $@ -c $? 

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

clean:
					rm -f $(OBJS) $(OBJS_PUSH_SWAP)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					rm -f $(PUSH_SWAP)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY: 			all, $(PUSH_SWAP), clean, fclean, re