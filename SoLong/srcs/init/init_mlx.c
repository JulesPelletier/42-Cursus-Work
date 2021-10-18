/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:43:55 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 15:57:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	color_utils(t_texture text, int x, int y)
{
	char	*dst;

	dst = text.data + (y * text.line_length + x * text.bits_per_pxl / 8);
	return (*(unsigned int *)dst);
}

void	init_ptr_mlx(t_all *all)
{
	all->window.mlx_ptr = mlx_init();
}
