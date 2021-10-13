/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:31:27 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/13 12:05:03 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define  SOLONG_H

# include "../Libft/libft.h"
# include "../minilibx/mlx.h"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307

/*
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define ESC 53
*/

typedef struct s_player
{
	int	x;
	int	y;
	int	up;
	int	side;
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
	char	*data;
	char	*name;
	int		bits_per_pxl;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_texture;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*name;
	t_img		img;
	int			h;
	int			w;
}				t_win;

typedef struct s_all
{
	char		**map;
	t_texture	texture[8];
	t_img		img;
	t_win		window;
	t_player	player;
	int			fd;
	int			size;
	int			n_col;
	int			width;
	int			height;
	int			x;
	int			y;
	int			n_rows;
	int			start;
	int			collectible;
	int			exit;
	int			error;
	int			move;
	int			end;
}				t_all;

void	load_window(t_all *all);
void	game_loop(t_all *all);
int		check_args(t_all *all, int argc, char *str, t_list **error);
void	free_all(t_all all);
void	load_textures(t_all *all);
void	check_arguments(t_all *all, t_list **error);
char	*add_spaces(char *str, int largest_line);
void	update_pos(t_all *all);
int		first_render(t_all *all);
int		color_utils(t_texture text, int x, int y);
void	init_ptr_mlx(t_all *all);
int		first_render(t_all *all);
void	load_image(t_all *all);
int		key_release(int key, t_player *player);
int		key_press(int key, t_all *all);
void	my_mlx_put_pxl(t_img *img, int x, int y, int color);
void	free_map(void *grid);
void	free_ptr(t_all *all);
void	free_g(t_all g);
void	free_texture(t_all *all);
void	add_error(t_all *all, t_list **error, char *str);
void	show_error(t_list *error);
void	init_all(t_all *all);
void	init_ptr_mlx(t_all *all);
int		close_cub(t_all *all);
void	free_global(t_list *list, t_all g, t_list *error);
void	init_all(t_all *all);
int		check_extension(char *file);
int		begin(t_all *all, int argc, char *file, t_list **error);
void	get_map(char *line, t_list **list);
int		is_in_str(char c, char *charset);
int		check_line(char *line, t_list **error, t_all *all);
void	check_borders(t_all *all, t_list **error);
void	free_map(void *grid);
int		count_grid(t_all *all, t_list *grid, t_list **error);

#endif
