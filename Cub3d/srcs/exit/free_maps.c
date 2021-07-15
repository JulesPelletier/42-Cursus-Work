/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:43:36 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:26:41 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free_maps_tabmapval(t_st *st)
{
	int	i;

	if (st->maps.tabmapval != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->maps.tabmapval[i] != NULL)
				free(st->maps.tabmapval[i]);
			i++;
		}
		free(st->maps.tabmapval);
	}
}

void	ft_free_maps_tabmaps(t_st *st)
{
	int	i;
	int	j;

	if (st->maps.tabmaps != NULL)
	{
		j = 0;
		while (j < st->maps.nbrmaps)
		{
			if (st->maps.tabmaps[j] != NULL)
			{
				i = 0;
				while (i < st->maps.tabmapval[j][MAP_H])
				{
					if (st->maps.tabmaps[j][i] != NULL)
						free(st->maps.tabmaps[j][i]);
					i++;
				}
				free(st->maps.tabmaps[j]);
			}
			j++;
		}
		free(st->maps.tabmaps);
	}
}

void	ft_free_maps(t_st *st)
{
	ft_free_maps_tabmaps(st);
	ft_free_maps_tabmapval(st);
}
