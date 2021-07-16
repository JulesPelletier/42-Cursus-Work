/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_sprtval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:34 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:45:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_sprtval_sprttype(t_st *st)
{
	int	**t1;
	int	*t2;
	int	i;

	t1 = malloc(sizeof(int *) * st->maps.nbrmaps);
	if (!(t1))
		ft_error(st, -14);
	st->sprt.tabsprttype = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
		st->sprt.tabsprttype[i++] = NULL;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			t2 = malloc(sizeof(int) * st->maps.tabmapval[i][N_SPRT]);
			if (!(t2))
				ft_error(st, -14);
			st->sprt.tabsprttype[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval_sprtposy(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	t1 = malloc(sizeof(double *) * st->maps.nbrmaps);
	if (!(t1))
		ft_error(st, -14);
	st->sprt.tabsprtposy = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
		st->sprt.tabsprtposy[i++] = NULL;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT]);
			if (!(t2))
				ft_error(st, -14);
			st->sprt.tabsprtposy[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval_sprtposx(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	t1 = malloc(sizeof(double *) * st->maps.nbrmaps);
	if (!(t1))
		ft_error(st, -14);
	st->sprt.tabsprtposx = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
		st->sprt.tabsprtposx[i++] = NULL;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT]);
			if (!(t2))
				ft_error(st, -14);
			st->sprt.tabsprtposx[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval(t_st *st)
{
	ft_tabinit_sprtval_sprtposx(st);
	ft_tabinit_sprtval_sprtposy(st);
	ft_tabinit_sprtval_sprttype(st);
}
