/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:34:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/10 13:54:58 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	draw(t_all *all)
{
	all->draw.x = 0;
	while (all->map.map[all->draw.x])
	{
		all->draw.y = 0;
		while (all->map.map[all->draw.x][all->draw.y])
		{
			ft_display(all, all->map.map[all->draw.x][all->draw.y]);
			all->draw.y++;
		}
		all->draw.x++;
	}
	return (1);
}
