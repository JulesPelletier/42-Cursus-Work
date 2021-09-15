/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:03:48 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:13:41 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "stdlib.h"
# include <unistd.h>
# include "get_next_line.h"
# include "../Libft/libft.h"
# include "../mlx-macos/mlx.h"
//# include "../mlx-linux/mlx.h"
# include "math.h"
# include <fcntl.h>

//LINUX

//# define KEY_PRESS 2
//# define KEY_RELEASE 3
//# define UP 119
//# define LEFT 97
//# define DOWN 115
//# define RIGHT 100
//# define ESC 65307

//MACOS

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define ESC 53

typedef struct s_coor
{
	float	x;
	float	y;
}	t_coor;

typedef struct s_float
{
	float	x;
	float	y;
}	t_float;

typedef struct s_gps
{
	t_float	pos;
	t_float	dir;
	float	square;
	int		height;
	int		width;
	t_float	plane;
	t_float	time;
	t_coor	move;
	int		event;
}	t_gps;

typedef struct s_img
{
	void			*image;
	char			*addr;
	int				bpp;
	int				endian;
	int				size_line;
	unsigned int	color;
	int				height;
	int				width;
}	t_img;

typedef struct s_input
{
	int		fd;
	char	*line;
	char	*map;
	char	**matrix;
	int		R[2];
	t_img	player;
	t_img	coin;
	t_img	exit;
	t_img	wall;
	t_img	floor;
	char	*index;
	int		index_i;
	int		tracker;
}	t_input;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img_map;
	t_img	img_perso;
}	t_mlx;

typedef struct s_map
{
	int	size_x;
	int	size_y;
	int	track_x;
	int	track_y;
	int	player_count;
	int	sprite_count;
	int	exit_count;
	int	map_length;
}	t_map;

typedef struct s_all
{
	t_input	args;
	t_mlx	mlx;
	t_gps	gps;
	int		moves;
	int		collectibles;
	int		exit;
	int		cross;
	t_map	map;
}	t_all;

//CHECKS 
void	check_collectibles(t_all *all);
int		check_spaces(t_all *all, int i, int f);
void	check_elems(t_all *all, int i, int f);
int		check_file(char *file);
void	check_map(t_all *all);

//CLEAN
int		ft_clean(t_all *all);

//CLEAR IMAGES
void	clear_images(t_all *all);

//CREATE MAP
void	create_map(t_input *args);

//DISPLAY
void	display_image(t_all *all, void *img);
void	check_display(t_all *all, char pos);

//DRAW MAP
void	redraw_pos(t_all *all, t_coor old_pos, int id);
void	redefine_pos(t_all *all);
void	draw_map(t_all *all);
void	draw(t_all *all);
int		new_map(t_all *all);

//ERROR 
void	error_display(int error);
void	error(t_all *all, int e);

//EVENT
int		event(t_all *all);

//GAME LOOP
void	game_loop(t_all *all);

//MAP PARSING
int		map_parsing(t_input *args, t_all *all);

//INIT
void	init_image(t_img *img);
void	init_all(t_all *all);

//KEYS
int		key_press(int keycode, t_all *all);
int		key_release(int keycode, t_all *all);

//MAIN
int		main(int argc, char **argv);

//MAP PARSING
int	map_parsing(t_input *args, t_all *all);

//STARTING POSITION
void	start_pos(t_all *all);

//TEXTURES
void	get_textures(t_all *all);


#endif