# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 16:34:26 by Jules             #+#    #+#              #
#    Updated: 2021/09/21 13:59:12 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLONG	 		=	so_long

CC 				=	gcc -fsanitize=address

CFLAGS 			=	-Wall -Wextra -Werror

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS			=	$(addprefix ./srcs/, ${SRCS_SOLONG})

SRCS_SOLONG		=	GNL/get_next_line.c			\
					check_parsing.c				\
					display.c					\
					errors.c					\
					free_map.c					\
					init_game.c					\
					init_structs.c				\
					keys.c						\
					load_image.c				\
					load_textures.c				\
					main.c						\
					parsing.c					\
					player.c					\
					utils.c						\
					utils2.c					\

OBJS_SOLONG		=	$(SRCS:.c=.o)

MLX_DIR 		=	minilibx/mlx_mac

INCDIRS 		= 	-IGNL -ILibft -Iminilibx_opengl -Iincludes

MLX_LIB 		=	$(MLX_DIR)/libmlx.a

MLX_LINKMAC 	=	-framework OpenGL -framework AppKit

MLX_LINKLNX 	=	-lX11 -lXext -lm -lbsd

all:				$(LIBFT_LIB) $(OBJS_SOLONG) $(SOLONG)

$(SOLONG):			$(OBJS_SOLONG) $(LIBFT_LIB)
					$(CC) $(OBJS_SOLONG) $(LIBFT_LIB) $(MLX_LIB) $(MLX_LINKMAC) -o $@

%.o:				%.c
					$(CC)  $(INCDIRS) -o $@ -c $?

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

$(MLX_LIB):
					echo lalala
					make -C $(MLX_DIR)

clean:
					rm -f $(OBJS_SOLONG)
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)

fclean:				clean
					rm -f $(SOLONG)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY: 			all, $(SOLONG), clean, fclean, re