/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:22:10 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:48:18 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../Libft/libft.h"
# include "../minilibx/mlx_mac/mlx.h"
# include "../srcs/GNL/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_PRESS 2
# define KEY_RELEASE 3

// LINUX
/*
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
*/
// MACOS

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct	s_params
{
	int		fd;
	int		size;
	int		n_columns;
	int		n_rows;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		start;
	int		moves;
}				t_params;


typedef struct	s_player
{
	int	x;
	int	y;
	int	hor;
	int	vert;
}				t_player;

typedef struct s_img
{
	void	*img;
	char	*adr;
	int		bits_per_pxl;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_texture
{
	void	*ptr;
	char	*name;
	t_img	image;
}				t_texture;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*name;
	t_img		img;
	int			h;
	int			w;
}				t_mlx;

typedef struct	s_all
{
	char		**map;
	t_params	params;
	t_mlx		mlx;
	t_img		image;
	t_player	player;
	t_texture	floor;
	t_texture	wall;
	t_texture	user;
	t_texture	collectible;
	t_texture	exit;
	t_texture	background;
	int			end;
	int			error;
	int			x_pixel;
	int			y_pixel;
}				t_all;

// Init
void	init_params(t_all *all);
void	init_player(t_all *all);
void	init_image(t_all *all);
void	init_texture(t_texture *texture);
void	init_all(t_all *all);

// Checks
int		check_extension(char *str);
void	check_n_arguments(t_all *all, t_list **error);
int		check_arguments(t_all *all, int ac, char *file, t_list **error);
int		check_lines(t_all *all);
int		check_columns(t_all *all);
void	check_borders(t_all *all, t_list **error);

// Init Game
void	init_game(t_all *all, char *file, t_list **list, t_list **error);

// Errors
void	add_error(t_all *all, t_list **error, char *error_msg);
void	show_errors(t_list *error);

// Parsing
int		count_columns(t_list *map);
void	convert_map(t_all *all, t_list *map, t_list **error);
int		create_map(t_all *all, t_list *map, t_list **error);

// Textures
void	load_textures(t_all *all, t_texture *texture);
void	get_textures(t_all *all);

// Display
void	display_texture(t_all *all, int x, int y, t_texture *text);
int		ft_display(t_all *all, int h, int w, t_texture *text);
void	texture_menu(t_all *all, int i, int j);
int		ft_display2(t_all *all);

// Player
int		check_move(t_all *all, int x, int y);
void	print_moves(t_all *all);
void	position_update(t_all *all);

// Keys
int		key_press(int key, t_all *all);
int		key_release(int key, t_all *all);

// Utils
void	del_list(void *list);
void	my_mlx_put_pxl(t_img *image, int x, int y, int color);
int		get_color(t_texture *text, int x, int y);
int		is_in_charset(char c, char *charset);
int		detect_map_line(t_all *all, char *line, t_list **error);
void	record_map(char *line, t_list **list);
void	load_map(t_all *all);
char	*add_spaces(char *str, int largest_line);
void	init_ptr_mlx(t_all *all);
void	load_image(t_all *all);

// Free
void	free_image(t_img *image);
void	free_ptr(t_all *all);
void	free_texture(t_all *all, t_texture *texture);
void	free_map(t_all *all);
void	free_all(t_all *all);
int		end_game(t_all *all);

#endif