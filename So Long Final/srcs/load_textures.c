/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:11:53 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:17:26 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_textures(t_all *all, t_texture *texture)
{
	texture->ptr = mlx_xpm_file_to_image(all->mlx.mlx_ptr, texture->name,
		&texture->image.w, &texture->image.h);
	texture->image.adr = mlx_get_data_addr(texture->ptr,
		&texture->image.bits_per_pxl, &texture->image.line_length,
		&texture->image.endian);
}

void	get_textures(t_all *all)
{
	//all->collectible.name = ft_strdup();
	//all->user.name = ft_strdup();
	//all->exit.name = ft_strdup();
	//all->floor.name = ft_strdup();
	//all->wall.name = ft_strdup();
	//all->background.name = ft_strdup();
	load_textures(all, &all->floor);
	load_textures(all, &all->wall);
	load_textures(all, &all->exit);
	load_textures(all, &all->collectible);
	load_textures(all, &all->user);
	load_textures(all, &all->background);
}