/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:13:06 by Jules             #+#    #+#             */
/*   Updated: 2021/07/26 17:48:01 by Jules            ###   ########.fr       */
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

void	new_min(t_push_swap *all, size_t count)
{
	if (all->stA.first <= all->stA.min && !all->stA.fsort && all->stA.len + all->stB.len <= 16)
	{
		all->stA.fsort = 1;
		update_output(all, "ra");
		return (new_min(all, 0));
	}
	if ((is_already_sorted(all) == 1) || (
			all->stA.first > all->stB.min && all->stB.len > 0))
		return ;
	if (all->stA.first <= all->stA.min)
	{
		all->stA.fsort = 1;
		update_output(all, "ra");
		return (new_min(all, 0));
	}
	count = check_value(&all->stA, all->stA.min) + 1;
	while (count < all->stA.len - 1)
	{
		if (all->stA.st[count] < all->stA.first)
			return ;
		count++;
	}
	all->stA.fmax = all->stA.first;
	update_output(all, "ra");
	return (new_min(all, 0));
}

void	fullpushb(t_push_swap *all)
{
	int		temp;

	while (all->stB.len > 0)
	{
		temp = minormax(all);
		check_first_b(all, temp);
		update_output(all, "pa");
		new_min(all, 0);
	}
}

void	bborneur(t_push_swap *all, int b_min, int b_max)
{
	if (!(b_min < b_max))
		return ;
	while (all->stB.len >= 14 && check_borne
		(&all->stB, b_min, all->stB.max) >= 1)
	{
		if ((all->stB.first >= b_min && all->stB.first <= all->stA.max)
			|| all->stB.first == all->stB.min)
		{
			update_output(all, "pa");
			new_min(all, 0);
		}
		else
			update_output(all, "rb");
	}
	fullpushb(all);
	aborneur(all, all->stA.fmax + 1, b_max);
}

void	aborneur(t_push_swap *all, int b_min, int b_max)
{
	if (!(b_min < b_max))
		return ;
	while (check_borne(&all->stA, b_min, b_max) == 1)
	{
		stack_update(&all->stA, 0);
		if (all->stA.first >= b_min && all->stA.first <= b_max)
			update_output(all, "pb");
		else
			update_output(all, "ra");
	}
	if (all->stA.fsort == 1)
	{
		while (all->stA.second != all->stA.fmax)
			update_output(all, "rra");
	}
	bborneur(all, get_median(&all->stB), b_max);
}
