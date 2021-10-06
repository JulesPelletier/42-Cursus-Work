/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:50:45 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 17:37:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	game_loop(t_all *all)
{
	init_ptr_mlx(all);
	load_image(all);
	load_window(all);
	load_textures(all);
	mlx_hook(all->window.win_ptr, 3, 1L << 1, key_release, &all->player);
	mlx_hook(all->window.win_ptr, 2, 1L << 0, key_press, all);
	mlx_loop_hook(all->window.mlx_ptr, first_render, all);
	mlx_hook(all->window.win_ptr, 33, 1L << 17, &close_cub, all);
	mlx_loop(all->window.mlx_ptr);
}
