# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 16:35:11 by Jules             #+#    #+#              #
#    Updated: 2021/08/19 17:12:35 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLONG	 		=	so_long

CC 				=	gcc -fsanitize=address

CFLAGS 			=	-Wall -Wextra -Werror -g3

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS_SOLONG	 	=	GNL/get_next_line.c							\
					srcs/parsing/check_args.c					\
					srcs/parsing/check_character.c				\
					srcs/parsing/check_extension.c				\
					srcs/parsing/check_borders.c				\
					srcs/parsing/get_map.c						\
					srcs/parsing/parsing.c						\
					srcs/errors/errors.c						\
					srcs/init/init_all.c						\
					srcs/init/init_params.c						\
					srcs/init/init_map.c						\
					srcs/init/init_game.c						\
					srcs/init/init_keys.c						\
					srcs/init/init_mlx.c						\
					srcs/init/init_player.c						\
					srcs/init/init_draw.c						\
					srcs/init/init_images.c						\
					srcs/init/init_image.c						\
					srcs/game/keys.c							\
					srcs/main.c									\
					srcs/show_struct.c							\
					srcs/game/file1.c							\
					srcs/game/moves.c							\
					srcs/game/game_start.c						\
					srcs/render/player.c						\
					srcs/render/load_images.c					\
					srcs/draw/draw.c							\


OBJS_SOLONG		=	$(SRCS_SOLONG:.c=.o)

MLX_DIR 		=	minilibx/mlx_mac

INCDIRS 		= 	-IGNL -ILibft -Iminilibx/mlx_mac -Iincludes

MLX_LIB 		=	$(MLX_DIR)/libmlx.a

MLX_LINKMAC 	=	-framework OpenGL -framework AppKit

MLX_LINKLNX 	=	-lX11 -lXext -lm -lbsd

all:				$(MLX_LIB) $(LIBFT_LIB) $(OBJS_SOLONG) $(SOLONG)

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