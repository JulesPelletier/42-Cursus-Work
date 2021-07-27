/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:26:33 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:10:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_push_swap *all)
{
	size_t		i;

	i = 0;
	while (i < all->stA.len - 1)
	{
		if (all->stA.st[(int)i] < all->stA.st[(int)i + 1])
			return (-1);
		i++;
	}
	if (all->stB.len != 0)
		return (-2);
	return (1);
}

int	is_already_sorted(t_push_swap *all)
{
	int	i;

	i = 0;
	while (i < (int)all->stA.len - 1)
	{
		if (all->stA.st[i] < all->stA.st[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
