/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:42:22 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 15:28:15 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	*ft_parsearg_mapinit_mapline(t_st *st, int linenbr, int i)
{
	int		*mapline;
	int		j;

	mapline = malloc(sizeof(int *) * (st->maps.sizemapx));
	if (!(mapline))
		ft_error(st, -14);
	j = 0;
	while (linenbr)
	{
		i++;
		if (st->pars.strmap[i] == '\n')
			linenbr--;
	}
	i++;
	while (st->pars.strmap[i] != '\n')
		mapline[j++] = st->pars.strmap[i++];
	while (j < st->maps.sizemapx)
	{
		mapline[j] = ' ';
		j++;
	}
	return (mapline);
}

void	ft_parsearg_mapinit_sizemapy(t_st *st)
{
	int	i;

	st->maps.sizemapy = 0;
	i = 0;
	while (st->pars.strmap[i])
	{
		if (st->pars.strmap[i] == '\n')
			st->maps.sizemapy++;
		i++;
	}
}

int	**ft_parsearg_mapinit_map(t_st *st)
{
	int	**map;
	int	i;

	ft_parsearg_mapinit_sizemapy(st);
	map = malloc(sizeof(int *) * st->maps.sizemapy);
	if (!(map))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.sizemapy)
	{
		map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.sizemapy)
	{
		map[i] = ft_parsearg_mapinit_mapline(st, i, -1);
		i++;
	}
	free(st->pars.strmap);
	st->pars.strmap = NULL;
	return (map);
}

void	indent(char *tmp1, char *tmp2 int *i)
{
	tmp1[*i] = tmp2[*i];
	i++;
}

void	ft_parsearg_mapinit(t_st *st)
{
	int	***tmp;
	int	i;

	st->pars.parsingmap = 0;
	tmp = malloc(sizeof(int **) * st->maps.nbrmaps);
	if (!(tmp))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		tmp[i] = NULL;
		i++;
	}
	if (st->maps.tabmaps != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps - 1)
			indent(tmp, st->maps.tabmaps, &i);
		free(st->maps.tabmaps);
	}
	st->maps.tabmaps = tmp;
	st->maps.tabmaps[st->maps.nbrmaps - 1] = ft_parsearg_mapinit_map(st);
	ft_parsearg_mapvalinit(st);
}
