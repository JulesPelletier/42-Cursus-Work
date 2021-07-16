/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapvalinit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:49:01 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:23:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_mapvalinit_val(t_st *st)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * 6);
	if (!(tmp))
		ft_error(st, -14);
	tmp[MAP_W] = st->maps.sizemapx;
	tmp[MAP_H] = st->maps.sizemapy;
	tmp[ST_X] = 0;
	tmp[ST_Y] = 0;
	tmp[ST_DIR] = 0;
	tmp[N_SPRT] = 0;
	st->maps.tabmapval[st->maps.nbrmaps - 1] = tmp;
}

void	ft_parsearg_mapvalinit(t_st *st)
{
	int	**tmp;
	int	i;

	tmp = malloc(sizeof(int *) * st->maps.nbrmaps);
	if (!(tmp))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.nbrmaps - 1)
	{
		tmp[i] = NULL;
		i++;
	}
	if (st->maps.tabmapval != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps - 1)
		{
			tmp[i] = st->maps.tabmapval[i];
			i++;
		}
		free(st->maps.tabmapval);
	}
	st->maps.tabmapval = tmp;
	ft_parsearg_mapvalinit_val(st);
	ft_parsearg_mapvalid(st);
}
