/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:32:58 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	game_loop(t_all *all)
{
	all->gps.move.x = 0;
	all->gps.event = 0;
	all->gps.move.y = 0;
	all->args.R[0] = 5000;
	all->args.R[1] = 5000;
	all->mlx.ptr = mlx_init();
	if (!all->mlx.ptr)
		ft_putstr_fd("Error initialising mlx", 1);
	all->mlx.win = mlx_new_window(all->mlx.ptr,
			all->args.R[0], all->args.R[1], "So_long");
	if (!all->mlx.win)
		ft_putstr_fd("Error creating window", 1);
	get_textures(all);
	draw_map(all);
	mlx_hook(all->mlx.win, KEY_PRESS, 1L << 0, &key_press, all);
	mlx_hook(all->mlx.win, 33, (1L << 17), ft_clean, all);
	mlx_hook(all->mlx.win, KEY_RELEASE, 1L << 1, &key_release, all);
	mlx_loop_hook(all->mlx.ptr, &event, all);
	mlx_loop(all->mlx.ptr);
}