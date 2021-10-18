/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:55:43 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 17:44:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	free_map(void *map)
{
	free(map);
	map = NULL;
}

void	my_mlx_put_pxl(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = img->adr + (y * img->line_length + x * (img->bits_per_pxl / 8));
		*(unsigned int *)dst = color;
	}
}

int	close_cub(t_all *all)
{
	if (all->collectible == 0)
	{
		ft_putstr("\n ====== GAME FINISHED ====== \n");
		ft_putstr("\n You won the game !!!\n");
		ft_putstr("\n ====== ============= ====== \n");
	}
	else
	{
		ft_putstr("\n ====== GAME OVER ====== \n");
		ft_putstr("\n You didn't manage to finish !!!\n");
		ft_putstr("\n ====== ========= ====== \n");
	}
	free_texture(all);
	free_ptr(all);
	free_all(*all);
	exit (0);
}
