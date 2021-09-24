/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:46:08 by Jules             #+#    #+#             */
/*   Updated: 2021/09/20 13:48:25 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_image(t_all *all)
{
	int	y;
	int	x;

	y = all->params.size * all->params.n_rows;
	x = all->params.size * all->params.n_columns;
	all->params.width = x;
	all->params.height = y;
	all->mlx.img.img = mlx_new_image(all->mlx.mlx_ptr, x, y);
	all->mlx.img.adr = mlx_get_data_addr(all->mlx.img.img,
		&all->mlx.img.bits_per_pxl, &all->mlx.img.line_length,
		&all->mlx.img.endian);
}