/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:13:06 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:52:50 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	minormax(t_push_swap *all)
{
	size_t	imin;
	size_t	imax;

	imin = check_value(&all->stB, all->stB.min);
	imax = check_value(&all->stB, all->stB.max);
	if (imin < all->stB.len / 2)
		imin++;
	else
		imin = all->stB.len - imin - 1;
	if (imax < all->stB.len / 2)
		imax++;
	else
		imax = all->stB.len - imax - 1;
	if (imax < imin)
		return (all->stB.max);
	return (all->stB.min);
}

void	new_min(t_push_swap *g, size_t count)
{
	if (g->stA.first <= g->stA.min && !g->stA.fsort && g->stA.len + g->stB.len <= 16)
	{
		g->stA.fsort = 1;
		update_output(g, "ra");
		return (new_min(g, 0));
	}
	if ((is_already_sorted(g) == 1) || (
			g->stA.first > g->stB.min && g->stB.len > 0))
		return ;
	if (g->stA.first <= g->stA.min)
	{
		g->stA.fsort = 1;
		update_output(g, "ra");
		return (new_min(g, 0));
	}
	count = check_value(&g->stA, g->stA.min) + 1;
	while (count < g->stA.len - 1)
	{
		if (g->stA.st[count] < g->stA.first)
			return ;
		count++;
	}
	g->stA.fmax = g->stA.first;
	update_output(g, "ra");
	return (new_min(g, 0));
}

void	fullpushb(t_push_swap *all)
{
	int		tmp;

	while (all->stB.len > 0)
	{
		tmp = minormax(all);
		check_first_b(all, tmp);
		update_output(all, "pa");
		new_min(all, 0);
	}
}

void	bborneur(t_push_swap *all, int bornemin, int bornemax)
{
	if (!(bornemin < bornemax))
		return ;
	while (all->stB.len >= 14 && check_borne
		(&all->stB, bornemin, all->stB.max) >= 1)
	{
		if ((all->stB.first >= bornemin && all->stB.first <= all->stA.max)
			|| all->stB.first == all->stB.min)
		{
			update_output(all, "pa");
			new_min(all, 0);
		}
		else
			update_output(all, "rb");
	}
	fullpushb(all);
	aborneur(all, all->stA.fmax + 1, bornemax);
}

void	aborneur(t_push_swap *all, int bornemin, int bornemax)
{
	if (!(bornemin < bornemax))
		return ;
	while (check_borne(&all->stA, bornemin, bornemax) == 1)
	{
		stack_update(&all->stA, 0);
		if (all->stA.first >= bornemin && all->stA.first <= bornemax)
			update_output(all, "pb");
		else
			update_output(all, "ra");
	}
	if (all->stA.fsort == 1)
	{
		while (all->stA.second != all->stA.fmax)
			update_output(all, "rra");
	}
	bborneur(all, get_median(&all->stB), bornemax);
}