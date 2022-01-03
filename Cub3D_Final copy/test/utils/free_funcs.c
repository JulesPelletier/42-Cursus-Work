/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:53 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:07:01 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_parsing(t_all *all, char *line)
{
	if (line)
		free(line);
	free_all(all);
	ft_exit("Error : parsing failed\n");
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_tex(void *mlx_ptr, t_texture *tex)
{
	(void)mlx_ptr;
	if (tex)
	{
		if (tex->texture)
			//mlx_destroy_image(mlx_ptr, tex->texture);
		free(tex);
	}
}

void	free_all(t_all *all)
{
	if (all->mlx_ptr)
		ft_lstclear(&(all->map_ptr), &free);
	if (all->map)
		free_map(all->map);
	if (all->mlx_ptr)
	{
		if (all->window_ptr)
			//mlx_destroy_window(all->mlx_ptr, all->window_ptr);
		if (all->image)
			//mlx_destroy_image(all->mlx_ptr, all->image);
		free_tex(all->mlx_ptr, all->tex->no_texture);
		free_tex(all->mlx_ptr, all->tex->ea_texture);
		free_tex(all->mlx_ptr, all->tex->we_texture);
		free_tex(all->mlx_ptr, all->tex->so_texture);
		free(all->mlx_ptr);
	}
	if (all->player)
		free(all->player);
	if (all->rays)
		free(all->rays);
	free(all);
}