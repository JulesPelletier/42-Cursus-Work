# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 20:36:41 by thhusser          #+#    #+#              #
#    Updated: 2021/07/24 20:36:41 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

FLAGS 		= -Wall -Wextra -Werror

SRCS		= $(addprefix ./srcs/, ${SRCS_FILES})

SRCS_BONUS	= $(addprefix ./srcs/, ${FILES_BONUS})

FILES_BONUS	=  	main.c \
				parser/check_borders.c \
				parser/maps.c \
				error.c \
				memory.c \
				parser/begin.c \
				utils/utils.c \
				init.c \
				key_events/key_events.c \
				utils/mlx_utils.c \
				bonus/display_bonus.c \
				images.c \
				textures.c \
				player.c \
				memory_2.c \

SRCS_FILES	= 	main.c \
				parser/check_borders.c \
				parser/maps.c \
				error.c \
				memory.c \
				parser/begin.c \
				utils/utils.c \
				init.c \
				key_events/key_events.c \
				utils/mlx_utils.c \
				display.c \
				images.c \
				textures.c \
				player.c \
				memory_2.c \
				
				

PATH_LIBFT 	= ./libft/

PATH_MLX	= ./minilibx/

HEADER		= -I ./includes

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

RM 			= rm -f

.c.o:
			@gcc ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME): 	${OBJS}
			@make bonus -C ${PATH_LIBFT}
			@gcc $(FLAGS) $(HEADER) $(OBJS) -o $(NAME) -L ${PATH_LIBFT} -lft -L ${PATH_MLX} -lmlx -lXext -lX11 -lm

bonus:		${OBJS_BONUS}
			@make bonus -C ${PATH_LIBFT}
			@gcc $(FLAGS) $(HEADER) ${OBJS_BONUS} -o $(NAME) -L ${PATH_LIBFT} -lft -L ${PATH_MLX} -lmlx -lXext -lX11 -lm

clean:	
			${RM} ${OBJS}
			@make clean -C ${PATH_LIBFT}

fclean:		clean
			${RM} ${NAME}
			@make fclean -C ${PATH_LIBFT}

re:			fclean all

.PHONY:		all clean fclean re bonus