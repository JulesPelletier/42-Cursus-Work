# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 16:35:11 by Jules             #+#    #+#              #
#    Updated: 2021/10/13 12:14:25 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLONG	 		=	so_long

CC 				=	gcc -fsanitize=address

CFLAGS 			=	-Wall -Wextra -Werror -g3

LIBFT_DIR 		=	Libft

LIBFT_LIB 		=	$(LIBFT_DIR)/libft.a

SRCS_SOLONG	 	=	srcs/parsing/check_borders.c					\
					srcs//parsing/check_args.c						\
					srcs/parsing/load_images.c						\
					srcs/parsing/load_window.c						\
					srcs/parsing/game_loop.c						\
					srcs/parsing/load_textures.c					\
					srcs/parsing/parse_map.c						\
					srcs/render/render.c							\
					srcs/init/init.c								\
					srcs/init/init_mlx.c							\
					srcs/utils/game_utils.c							\
					srcs/utils/utils.c								\
					srcs/utils/utils2.c								\
					srcs/utils/utils3.c								\
					srcs/main.c										\
					srcs/error.c									\
					srcs/keys.c										\


OBJS_SOLONG		=	$(SRCS_SOLONG:.c=.o)

MLX_DIR 		=	minilibx/

INCDIRS 		= 	-IGNL -ILibft -Iminilibx_opengl -Iincludes

MLX_LIB 		=	$(MLX_DIR)/libmlx.a

MLX_LINKMAC 	=	-framework OpenGL -framework AppKit

all:				$(LIBFT_LIB) $(OBJS_SOLONG) $(SOLONG)

$(SOLONG):			$(OBJS_SOLONG) $(LIBFT_LIB)
					$(CC) $(OBJS_SOLONG) $(LIBFT_LIB) $(MLX_LIB) $(MLX_LINKMAC) -o $@

%.o:				%.c
					$(CC)  $(INCDIRS) -o $@ -c $?

$(LIBFT_LIB):
					make bonus -C $(LIBFT_DIR)

clean:
					rm -f $(OBJS_SOLONG)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					rm -f $(SOLONG)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY: 			all, $(SOLONG), clean, fclean, re