/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:09:13 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 15:21:22 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int show(t_all *all)
{
    show_map(all);
    return (1);
}

int main(int ac, char **av)
{
    t_all all;

    init_all(&all);
    if (check_args(ac, av) == -1)
        return (-1);
    all.map.filename = av[1];
    if (parsing(&all, ac, av) == -1)
        return (0);
    all.mlx.mlx_ptr = mlx_init();
    if (all.mlx.mlx_ptr == NULL)
    {
        printf("POINTER NULL\n");
        return (0);
    }
    all.mlx.win_ptr = mlx_new_window(all.mlx.mlx_ptr,
        WIN_WIDTH, WIN_HEIGHT, "So_Long");
    if (all.mlx.win_ptr == NULL)
    {
        printf("WINDOW NULL\n");
        return (0);
    }
    load_textures(&all);
    game_start(&all);

    mlx_hook(all.mlx.win_ptr, 2, (1L << 0), keypress, &all);
	mlx_hook(all.mlx.win_ptr, 3, (1L << 1), keyrelease, &all);
	mlx_loop_hook(all.mlx.mlx_ptr, draw, &all);
	mlx_loop(all.mlx.mlx_ptr);
    free(all.mlx.mlx_ptr);
    show_struct(&all);
    return (0);
}