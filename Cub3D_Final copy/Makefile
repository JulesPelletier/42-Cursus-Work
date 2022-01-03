# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:32:52 by julpelle          #+#    #+#              #
#    Updated: 2022/01/02 22:33:06 by julpelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3D

NAME_BONUS 		=	cub3D_bonus

SRCS 			=	main.c								\
					../fcts/gnl/get_next_line.c			\
					parsing/ft_parsing1.c				\
					parsing/ft_parsing2.c				\
					parsing/ft_parsing3.c				\
					parsing/ft_parsing4.c				\
					parsing/ft_parsing5.c				\
					utils/utils1.c						\
					

SRCS_BONUS 		=

OBJS 			=	$(addprefix srcs/,$(SRCS:.c=.o))

OBJS_BONUS 		=	$(addprefix srcs_bonus/,$(SRCS_BONUS:.c=.o))

CC 				= 	clang -fsanitize=address -g3

CFLAGS 			= 	-Wall -Wextra -Werror

LIBFT 			= 	-L fcts/libft -lft

MLX_LIB			=	-L fcts/mlx -lmlx

MLX				=	-framework OpenGL -framework AppKit

MLX_LNX 		= 	-L fcts/mlx -lmlx -lX11 -lXext

MATH 			= 	-lm

RM 				= 	rm -f

all: 				$(NAME)

bonus: 				$(NAME_BONUS)

$(NAME_BONUS): 		$(OBJS_BONUS)
					make -C fcts/libft/
					make -C fcts/mlx/
					echo "\033[36;1mCreation :\033[0m \033[35;4m$(NAME_BONUS)\033[0m"
					$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MATH)

$(NAME): 			$(OBJS)
					make -C fcts/libft/
					make -C fcts/mlx/
					echo "\033[36;1mCreation :\033[0m \033[35;4m$(NAME)\033[0m"
					$(CC) $(CFLAGS) $(MLX_LIB) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MATH)

clean:
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)
					make -C fcts/libft/ clean
					make -C fcts/mlx/ clean

fclean: 			clean
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					make -C fcts/libft/ fclean

re: 				fclean all

re_bonus: 			fclean bonus

.PHONY: 			all clean fclean re bonus re_bonus
