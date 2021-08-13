/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:25 by Jules             #+#    #+#             */
/*   Updated: 2021/08/13 11:55:05 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <math.h>
# include "../minilibx/mlx_linux/mlx.h"
# include "../minilibx/mlx_mac/mlx.h"
# include "../Libft/libft.h"
# include "../GNL/get_next_line.h"
# include "/usr/X11/include/X11/X.h"

# define GREEN "\033[38;2;57;181;74m"
# define RED "\033[38;2;222;56;43m"
# define BLUE "\033[38;2;34;183;235m"
# define YELLOW "\033[38;2;255;176;0m"
# define PURPLE "\033[38;2;255;105;180m"
# define RESET "\033[0m"

# define COLOR_RED 0xFF0000
# define COLOR_BLUE 0x0000FF
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_WHITE 0xFFFFFF

# define WIN_HEIGHT 800
# define WIN_WIDTH 1080

typedef struct s_map_params
{
    int len_x;
    int len_y;
    int count_exit;
    int count_starting_pos;
    int count_collect;
    int flag_map_closed;
    int flag_extension;
    int flag_rectangular;
}               t_map_params;

typedef struct  s_map
{
    char    *filename;
    char    **map;
}               t_map;

typedef struct s_game
{
    int     start_x;
    int     start_y;
    int     current_x;
    int     current_y;
    int     collected;
    int     img_width;
    int     img_height;
}               t_game;

typedef struct s_keys
{
    int     key_w;
    int     key_a;
    int     key_s;
    int     key_d;
    int     key_esc;
}               t_keys;


typedef struct  s_mlx
{
    void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			img_bpp;
	int			img_sl;
	int			img_end;
}               t_mlx;


typedef struct  s_all
{
    t_map_params    params;
    t_map           map;
    t_game          game;
    t_mlx           mlx;
    t_keys          keys;
}               t_all;

int     check_extension(char *str);
int     check_file_or_dir(char *str);
int     check_args(int ac, char **av);
int     check_character(char c);
int     check_map_char(t_all *all);
void    check_params(t_all *all);
void    check_rectangular(t_all *all);
void    check_border(t_all *all);
int     final_param_check(t_all *all);
int     parsing(t_all *all, int ac, char **av);



void    get_map_size(char *str, t_all *all);
void    create_map(t_all *all);

void    errors_part1(int error);
void    ft_keypress(t_all *all, int key);
void    ft_keyrelease(t_all *all, int key);
int     keypress(t_all *all, int key);
int     keyrelease(t_all *all, int key);
int     ft_keys(t_all *all);



void    init_params(t_all *all);
void    init_mlx(t_all *all);
void    init_map(t_all *all);
void    init_game(t_all *all);
void    init_keys(t_all *all);
void    init_all(t_all *all);

// TESTS

void    show_struct(t_all *all);
void    show_map(t_all *all);
int     show_keys(t_all *all);

int     handle_no_event(t_all *all);
int     handle_input(t_all *all, int key);
int     handle_output(t_all *all, int key);
int     render(t_all *all);
int     render_big_square(t_all *all);
void    calculate_h_and_w(t_all *all);
int     test(t_all *all);



#endif