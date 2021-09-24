/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:18:32 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:50:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	free_image(t_img *image)
{
	image->img = NULL;
	image->adr = NULL;
}

void	free_ptr(t_all *all)
{
	if (all->mlx.mlx_ptr)
	{
		if (all->mlx.win_ptr)
		{
			if (all->mlx.img.img)
				free_image(&all->mlx.img);
			mlx_destroy_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
		}
		//mlx_destroy_display(all->mlx.mlx_ptr);
		free(all->mlx.mlx_ptr);
		all->mlx.mlx_ptr = NULL;
	}
}

void	free_texture(t_all *all, t_texture *texture)
{
	if (texture->ptr)
	{
		mlx_destroy_image(all->mlx.mlx_ptr, texture->image.img);
		texture->ptr = NULL;
		free_image(&texture->image);
	}
	if (texture->name)
	{
		free(texture->name);
		texture->name = NULL;
	}
}

void	free_map(t_all *all)
{
	int	i;
	
	i = 0;
	if (all->map)
	{
		while (i < all->params.n_rows)
			free(all->map[i++]);
		free(all->map);
	}
}

void	free_all(t_all *all)
{
	free_ptr(all);
	free_texture(all, &all->collectible);
	free_texture(all, &all->exit);
	free_texture(all, &all->user);
	free_texture(all, &all->wall);
	free_texture(all, &all->floor);
	free_texture(all, &all->background);
	free_map(all);

}

int	end_game(t_all *all)
{
	ft_putstr_fd("\n ----- End of the game ----- \n", 1);
	free_all(all);
	free_ptr(all);
	free_map(all);
	exit(0);
}