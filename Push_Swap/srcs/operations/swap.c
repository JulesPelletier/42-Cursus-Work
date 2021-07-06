/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:52:39 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 10:04:25 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_sa_move(t_all *all)
{
    int     tmp;

    tmp = 0;
    if (all->stA.len > 1)
    {
        tmp = all->stA.stack[0];
        all->stA.stack[0] = all->stA.stack[1];
        all->stA.stack[1] = tmp;
    }
}

void    ft_sb_move(t_all *all)
{
    int     tmp;

    tmp = 0;
    if (all->stB.len > 1)
    {
        tmp = all->stB.stack[0];
        all->stB.stack[0] = all->stB.stack[1];
        all->stB.stack[1] = tmp;
    }
}

void    ft_ss_move(t_all *all)
{
    ft_sa_move(all);
    ft_sb_move(all);
}