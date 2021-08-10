# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 15:10:36 by Jules             #+#    #+#              #
#    Updated: 2021/08/10 14:19:59 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX	 		=	pipex

CC 				=	gcc

CFLAGS 			=	-Wall -Wextra -Werror -g3 

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS_PIPEX	 	=	srcs2/pipex.c				\

								
OBJS_PIPEX		=	$(SRCS_PIPEX:.c=.o)

all:				$(LIBFT_LIB) $(OBJS_PIPEX) $(PIPEX)

$(PIPEX):			$(OBJS_PIPEX) $(LIBFT_LIB) 
					$(CC) $(CFLAGS) $(OBJS_PIPEX) $(LIBFT_LIB) -o $@ 


%.o:				%.c
					$(CC) $(CFLAGS)  -I. -o $@ -c $? 

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

clean:
					rm -f $(OBJS_PIPEX)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					rm -f $(PIPEX)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY: 			all, $(PIPEX), clean, fclean, re