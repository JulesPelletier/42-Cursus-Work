/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:51:16 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:47:31 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	start_pos(t_all *all)
{
	int	i;
	int	f;

	all->gps.pos.y = -1;
	all->gps.pos.x = -1;
	i = 0;
	while (all->args.matrix[i])
	{
		f = 0;
		while (all->args.matrix[i][f])
		{
			if (all->args.matrix[i][f] == 'P')
			{
				all->gps.pos.x = f + 0.5;
				all->gps.pos.y = i + 0.5;
				break ;
			}
			f++;
		}
		i++;
	}
}
