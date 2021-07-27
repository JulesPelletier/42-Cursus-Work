/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quinze_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:25:43 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:03:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_quinze_plus(t_push_swap *all)
{
	int		b_max;
	int		b_min;

	b_min = all->stA.min;
	all->stA.fsort = 0;
	all->stB.fsort = 0;
	all->stA.fmax = all->stA.min - 1;
	while (is_already_sorted(all) < 1)
	{
		b_max = get_median(&all->stA);
		if (b_max <= b_min)
		{
			if (all->stA.st[all->stA.len - 1] > all->stA.st[all->stA.len - 2])
				update_output(all, "sa");
			update_output(all, "ra");
			update_output(all, "ra");
			return ;
		}
		aborneur(all, b_min, b_max);
		b_min = all->stA.fmax + 1;
	}
}
