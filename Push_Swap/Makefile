# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 14:53:02 by Jules             #+#    #+#              #
#    Updated: 2021/04/30 14:23:55 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CHECKER 		=	checker

PUSH_SWAP 		=	push_swap

CC 				=	gcc

CFLAGS 			=	-Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS_CHECKER 	=	srcs/checker/checker.c							\

SRCS_PUSH_SWAP 	=	srcs/push_swap/push_swap.c				\
					srcs/push_swap/ft_sort_three.c			\
					srcs/push_swap/algo.c					\
					srcs/push_swap/ft_simple_case.c			\


SRCS 			=	srcs/checker/ft_show_stack.c			\
					srcs/checker/ft_fill_stack.c			\
					srcs/checker/ft_max.c					\
					srcs/checker/check_doublons.c			\
					srcs/checker/check_sorted.c				\
					GNL/get_next_line_utils.c		\
					GNL/get_next_line.c				\
					srcs/checker/init_struct.c				\
					srcs/checker/check_op.c					\
					srcs/checker/ft_display_errors.c		\
					srcs/operations/push.c				\
					srcs/operations/swap.c				\
					srcs/operations/operation_menu.c		\
					srcs/operations/rotate_1.c			\
					srcs/operations/rotate_2.c			\
					srcs/push_swap/ft_get_divider.c			\
					srcs/push_swap/ft_get_maxmin.c			\
					srcs/push_swap/ft_check_stack.c			\

					
					
OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)

OBJS			=	$(SRCS:.c=.o)


all:				$(LIBFT_LIB) $(OBJS) $(CHECKER) $(PUSH_SWAP)

$(CHECKER):		 	$(OBJS_CHECKER) $(OBJS) $(LIBFT_LIB)
					$(CC) $(CFLAGS) $(OBJS_CHECKER) $(OBJS) $(LIBFT_LIB) -o $@ 

$(PUSH_SWAP):		$(OBJS_PUSH_SWAP) $(OBJS) $(LIBFT_LIB) 
					$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS) $(LIBFT_LIB) -o $@ 


%.o:				%.c
					$(CC) $(CFLAGS)  -I. -o $@ -c $? 

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

clean:
					rm -f $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					rm -f $(CHECKER) $(PUSH_SWAP)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY: 			all, $(CHECKER), $(PUSH_SWAP), clean, fclean, re
