/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_distandorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:22:37 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:37:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_distandorder_sprtorder(t_st *st)
{
	int	**t1;
	int	*t2;
	int	i;

	t1 = malloc(sizeof(int *) * st->maps.nbrmaps);
	if (!(t1))
		ft_error(st, -14);
	st->sprt.tabsprtorder = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
		st->sprt.tabsprtorder[i++] = NULL;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			t2 = malloc(sizeof(int) * st->maps.tabmapval[i][N_SPRT]);
			if (!(t2))
				ft_error(st, -14);
			st->sprt.tabsprtorder[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_distandorder_sprtdist(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	t1 = malloc(sizeof(double *) * st->maps.nbrmaps);
	if (!(t1))
		ft_error(st, -14);
	st->sprt.tabsprtdist = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
		st->sprt.tabsprtdist[i++] = NULL;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT]);
			if (!(t2))
				ft_error(st, -14);
			st->sprt.tabsprtdist[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_distandorder_walldist(t_st *st)
{
	double	*tmp;

	tmp = malloc(sizeof(double) * st->win.winw);
	if (!(tmp))
		ft_error(st, -14);
	st->wall.tabwalldist = tmp;
}

void	ft_tabinit_distandorder(t_st *st)
{
	ft_tabinit_distandorder_walldist(st);
	ft_tabinit_distandorder_sprtdist(st);
	ft_tabinit_distandorder_sprtorder(st);
}
