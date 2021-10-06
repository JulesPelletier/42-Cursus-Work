/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:50:45 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 16:34:25 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_image(t_all *all)
{
	int	y;
	int	x;

	y = all->size * all->n_rows;
	x = all->size * all->n_col;
	all->width = x;
	all->height = y;
	all->window.img.img = mlx_new_image(all->window.mlx_ptr, x, y);
	all->window.img.adr = mlx_get_data_addr(all->window.img.img,
			&all->window.img.bits_per_pxl, &all->window.img.line_length,
			&all->window.img.endian);
}
