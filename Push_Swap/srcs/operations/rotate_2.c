/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:10:44 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 10:05:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_rra_move(t_all *all)
{
    int     i;
    int     tmp;

    if (all->stA.len > 1)
    {
        i = all->stA.len - 1;
        tmp = all->stA.stack[all->stA.len - 1];
        while (i > 0)
        {
            all->stA.stack[i] = all->stA.stack[i - 1];
            i--;
        }
        all->stA.stack[0] = tmp;
    }
}

void    ft_rrb_move(t_all *all)
{
    int     i;
    int     tmp;

    if (all->stB.len > 1)
    {
        i = all->stB.len - 1;
        tmp = all->stB.stack[all->stB.len - 1];
        while (i > 0)
        {
            all->stB.stack[i] = all->stB.stack[i - 1];
            i--;
        }
        all->stB.stack[0] = tmp;
    }
}

void    ft_rrr_move(t_all *all)
{
    ft_rra_move(all);
    ft_rrb_move(all);
}