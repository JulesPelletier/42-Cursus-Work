# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jules <Jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by Jules             #+#    #+#              #
#    Updated: 2021/09/16 01:42:18 by Jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_S 		=	srcs

DIR_O 		=	objs

SOURCES 	= 	checks.c						\
				clear_images.c					\
				draw_map.c						\
				get_next_line.c 				\
				get_next_line_utils.c 			\
				create_map.c		 			\
				init.c							\
				map_parsing.c 					\
				main.c 							\
				keys.c							\
				clean.c							\
				game_loop.c						\
				starting_position.c				\
				event.c							\
				get_next_line.c 				\
				get_next_line_utils.c			\
				textures.c						\
				error.c							\
				display.c						\
				check_map_closed.c				\

SRCS 		=	$(addprefix $(DIR_S)/,$(SOURCES))

OBJS 		=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS 	=	headers

LIBFT_DIR 	= 	Libft

NAME = so_long

######################################################
## OS

MLX_DIR 	=	mlx-macos

CC 			= 	gcc

CFLAGS 		= 	-Wall -Wextra -Werror -g -fsanitize=address

LIBS 		= 	-framework OpenGL -framework Appkit


######################################################
## LINUX

##MLX_DIR 	=	 mlx-linux

##CC 		= 	clang

##LIBS 		=	-lXext -lX11 -lm

##-I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext 


MLX 		= 	$(addprefix $(MLX_DIR)/,libmlx.a)

LIBFT 		= 	$(addprefix $(LIBFT_DIR)/,libft.a)

all: 			$(LIBFT) $(MLX) $(NAME)

$(DIR_O)/%.o: 	$(DIR_S)/%.c
				mkdir -p $(DIR_O)	
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): 		$(OBJS) $(LIBFT) $(MLX)
				$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):
				make -C $(LIBFT_DIR)

$(MLX):
				make -C $(MLX_DIR)

clean:
				rm -f $(OBJS)		
				rm -f $(OBJS)/*.o
				rm -rf $(DIR_O)	
				make clean -C $(LIBFT_DIR)	
				make clean -C $(MLX_DIR)

fclean: 		clean
				rm -rf $(NAME)
				make fclean -C $(LIBFT_DIR)

re: 			fclean all

.PHONY: 		re fclean all clean