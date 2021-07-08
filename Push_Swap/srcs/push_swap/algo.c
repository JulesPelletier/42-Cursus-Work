/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:35:42 by Jules             #+#    #+#             */
/*   Updated: 2021/04/30 14:45:32 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_insert_after_mid(t_all *all, int pos)
{
    int count;

    count = 0;
    while (count < all->stA.len - pos + 1)
    {
        ft_rra_move(all);
        ft_putstr("rra 1\n");    
        count++;
    }
    ft_insert_min(all);
}

void    ft_insert_before_mid(t_all *all, int pos)
{
    int count;

    count = pos;
    ft_insert_min(all);
    while (count >= 1)
    {
        ft_ra_move(all);
        ft_putstr("ra 2\n");    
        count--;
    }
}

void    ft_rearrange(t_all *all)
{
    int     pos;

    pos = 0;
    while (all->stB.len != 0)
    {
        //printf("POS : %d\n", pos);
        //printf("TEST : %d\n", all->stA.len / 2 - 1);
        pos = ft_find_inser_pos(&all->stA, all->stB.stack[0]);
        if (pos == 0)
            ft_insert_min(all);
        else
        {
            if (pos > all->stA.len / 2 - 1)
                ft_insert_after_mid(all, pos);
            else
                ft_insert_before_mid(all, pos);
        }
    }
}

void    ft_test_5(t_all *all)
{
    while (all->stB.len != 0)
    {
        
    }
}

void    ft_algo(t_all *all)
{
    int     pos;

    pos = 0;
    ft_trivial(all);
    if (all->stA.len > 3 && all->stA.len < 20)
    {
        while (all->stA.len > 3)
        {
            ft_pb_move(all);
            ft_putstr("pb\n");    
        }
        ft_options_three(all, &all->stA);
        //ft_rearrange(all);
    }
}