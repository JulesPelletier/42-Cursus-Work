/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:04:44 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 12:07:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra_move(t_all *all)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = all->stA.stack[0];
	while (i < all->stA.len - 1)
	{
		all->stA.stack[i] = all->stA.stack[i + 1];
		i++;
	}
	all->stA.stack[i] = tmp;
}

void	ft_rb_move(t_all *all)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = all->stB.stack[0];
	while (i < all->stB.len - 1)
	{
		all->stB.stack[i] = all->stB.stack[i + 1];
		i++;
	}
	all->stB.stack[i] = tmp;
}

void	ft_rr_move(t_all *all)
{
	ft_ra_move(all);
	ft_rb_move(all);
}
