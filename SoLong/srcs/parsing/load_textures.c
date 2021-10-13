/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:51:55 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 16:57:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_textures(t_all *all)
{
	int	i;

	i = -1;
	all->texture[0].name = ft_strdup("./textures/wheel.xpm");
	all->texture[1].name = ft_strdup("./textures/empty.xpm");
	all->texture[2].name = ft_strdup("./textures/mario.xpm");
	all->texture[3].name = ft_strdup("./textures/ticket.xpm");
	all->texture[4].name = ft_strdup("./textures/checker_flag.xpm");
	while (++i < 5)
	{
		all->texture[i].ptr = mlx_xpm_file_to_image(all->window.mlx_ptr,
				all->texture[i].name, &all->texture[i].w, &all->texture[i].h);
		all->texture[i].data = mlx_get_data_addr(all->texture[i].ptr,
				&all->texture[i].bits_per_pxl, &all->texture[i].line_length,
				&all->texture[i].endian);
	}
}
