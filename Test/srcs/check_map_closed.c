/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:38:19 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 01:52:16 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_closed(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->args.matrix[i])
	{
		j = 0;
		while (all->args.matrix[i][j])
		{
			if (((i == 0 || i == all->map.size_x)
				|| (j == 0 || j == all->map.size_y)))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}