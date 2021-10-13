/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:40:41 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/13 12:15:03 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	free_image(t_all *all)
{
	mlx_destroy_image(all->window.mlx_ptr, all->window.img.img);
	all->window.img.img = NULL;
	all->window.img.adr = NULL;
}

void	free_ptr(t_all *all)
{
	if (all->window.mlx_ptr)
	{
		if (all->window.win_ptr)
		{
			if (all->window.img.img)
				free_image(all);
			mlx_destroy_window(all->window.mlx_ptr, all->window.win_ptr);
		}
		mlx_destroy_display(all->window.mlx_ptr);
		free(all->window.mlx_ptr);
		all->window.mlx_ptr = NULL;
	}
}

void	free_all(t_all all)
{
	int	i;

	i = 0;
	if (all.map)
	{
		while (i < all.n_rows)
			free(all.map[i++]);
		free(all.map);
	}
}

void	free_texture(t_all *all)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (all->texture[i].ptr)
		{
			mlx_destroy_image(all->window.mlx_ptr, all->texture[i].ptr);
			all->texture[i].ptr = NULL;
			all->texture[i].data = NULL;
		}
		if (all->texture[i].name)
		{
			free(all->texture[i].name);
			all->texture[i].name = NULL;
		}
		i++;
	}
}

void	free_global(t_list *list, t_all all, t_list *error)
{
	ft_lstclear(&list, &free_map);
	ft_lstclear(&error, &free_map);
	free_texture(&all);
	free_all(all);
}
