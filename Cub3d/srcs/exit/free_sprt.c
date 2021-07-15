/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:49:45 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:26:58 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free_sprt_distandorder(t_st *st)
{
	int	i;

	if (st->sprt.tabsprtdist != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->sprt.tabsprtdist[i] != NULL)
				free(st->sprt.tabsprtdist[i]);
			i++;
		}
		free(st->sprt.tabsprtdist);
	}
	if (st->sprt.tabsprtorder != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->sprt.tabsprtorder[i] != NULL)
				free(st->sprt.tabsprtorder[i]);
			i++;
		}
		free(st->sprt.tabsprtorder);
	}
}

void	ft_free_sprt_type(t_st *st)
{
	int	i;

	if (st->sprt.tabsprttype != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->sprt.tabsprttype[i] != NULL)
				free(st->sprt.tabsprttype[i]);
			i++;
		}
		free(st->sprt.tabsprttype);
	}
}

void	ft_free_sprt_pos(t_st *st)
{
	int	i;

	if (st->sprt.tabsprtposx != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->sprt.tabsprtposx[i] != NULL)
				free(st->sprt.tabsprtposx[i]);
			i++;
		}
		free(st->sprt.tabsprtposx);
	}
	if (st->sprt.tabsprtposy != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps)
		{
			if (st->sprt.tabsprtposy[i] != NULL)
				free(st->sprt.tabsprtposy[i]);
			i++;
		}
		free(st->sprt.tabsprtposy);
	}
}

void	ft_free_sprt_pathsprt(t_st *st)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (st->sprt.pathsprt[i] != NULL)
			free(st->sprt.pathsprt[i]);
		i++;
	}
}

void	ft_free_sprt(t_st *st)
{
	ft_free_sprt_pathsprt(st);
	ft_free_sprt_pos(st);
	ft_free_sprt_type(st);
	ft_free_sprt_distandorder(st);
}
