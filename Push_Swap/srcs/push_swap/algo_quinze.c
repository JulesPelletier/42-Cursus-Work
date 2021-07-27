/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quinze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:59:04 by Jules             #+#    #+#             */
/*   Updated: 2021/07/26 17:48:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_quinze(t_push_swap *all)
{
	while (all->stA.len > 3)
	{
		check_first_a(all, all->stA.min);
		update_output(all, "pb");
	}
	if (is_sorted(all) < 1)
		algo_three(all);
	while (all->stB.len > 0)
		update_output(all, "pa");
}