/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:09:43 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:25:38 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc(t_st *st, int save)
{
	st->mlx.img_ptr = mlx_new_image(
			st->mlx.mlx_ptr, st->win.winw, st->win.winh);
	st->mlx.img_data = (int *)mlx_get_data_addr(
			st->mlx.img_ptr, &st->mlx.img_bpp,
			&st->mlx.img_sl, &st->mlx.img_end);
	ft_rayc_ceiling(st);
	ft_rayc_floor(st);
	ft_rayc_walls(st);
	if (st->maps.tabmapval[st->coor.currlvl][N_SPRT] > 0)
		ft_rayc_sprt(st);
	mlx_put_image_to_window(
		st->mlx.mlx_ptr, st->mlx.win_ptr, st->mlx.img_ptr, 0, 0);
	if (save == 0)
		mlx_destroy_image(st->mlx.mlx_ptr, st->mlx.img_ptr);
}
