/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:01:36 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 13:39:02 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    load_collectibles(t_all *all)
{
	all->collect = load_image(all->mlx.mlx_ptr,
			"./srcs/textures/collectibles1-64_st-transpt.xpm");
	if (!(all->collect.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
	}
    all->collect.img_link = ft_strdup("./srcs/textures/collectibles1-64_st-transpt.xpm");
}

void	load_exit(t_all *all)
{
	all->exit = load_image(all->mlx.mlx_ptr,
			"./srcs/textures/exit-fond64t-transp.xpm");
	if (!(all->exit.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
	}
    all->exit.img_link = ft_strdup("./srcs/textures/exit-fond64t-transp.xpm");
}

void	load_floor(t_all *all)
{
	all->floor = load_image(all->mlx.mlx_ptr,
			"./srcs/textures/sol.xpm");
	if (!(all->floor.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
	}
    all->floor.img_link = ft_strdup("./srcs/textures/sol.xpm");
}

void	load_wall(t_all *all)
{
	all->wall = load_image(all->mlx.mlx_ptr,
			"./srcs/textures/wale-64-1.xpm");
	if (!(all->wall.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
	}
    all->wall.img_link = ft_strdup("./srcs/textures/wale-64-1.xpm");
}

void	load_all_images(t_all *all)
{
	load_collectibles(all);
	load_exit(all);
	load_floor(all);
	load_wall(all);
}