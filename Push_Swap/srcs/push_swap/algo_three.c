/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:53:18 by Jules             #+#    #+#             */
/*   Updated: 2021/07/26 17:48:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    algo_three(t_push_swap *all)
{
	if (all->stA.st[2] > all->stA.st[0])
	{
		if (all->stA.st[2] > all->stA.st[1])
		{
			update_output(all, "ra");
			if ((all->stA.st[2] > all->stA.st[1]))
				update_output(all, "sa");
		}
		else
		{ 
			update_output(all, "rra");
		}
	}
	else if (all->stA.st[1] < all->stA.st[2])
		update_output(all, "sa");
	else
	{
		update_output(all, "rra");
		update_output(all, "sa");
	}
}