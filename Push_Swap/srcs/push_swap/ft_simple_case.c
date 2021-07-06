/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:16:20 by Jules             #+#    #+#             */
/*   Updated: 2021/04/30 14:42:57 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     ft_find_inser_pos(t_stack *stack, int value)
{
    int     i;
    int     ret;

    i = 0;
    ret = 0;
    while (i < stack->len - 1)
    {
        if (stack->stack[i] < value)
        {
            if (stack->stack[i] < stack->stack[ret])
                ret = i;
        }
        i++;
    }
    return (i);
}

void    ft_trivial(t_all *all)
{
    int     count;

    count = all->stA.len;
    if (all->stA.len == 1 && all->stB.len == 0)
        all->err.kill = 1;
    if (all->stA.len == 2)
    {
        if (all->stA.params.index_max < all->stA.params.index_min)
        {
            ft_sa_move(all);
            ft_putstr("sa\n");    
        }
        if (all->stB.len == 0)
            all->err.kill = 1;
    }
    if (all->stA.len == 3  && all->stB.len == 0)
    {
        ft_options_three(all, &all->stA);
        all->err.kill = 1;
    }
}

void    ft_insert_min(t_all *all)
{
    if (all->stB.stack[0] < all->stA.stack[0])
    {
        ft_pa_move(all);
        ft_putstr("pa\n");
    }
}

void    ft_insert_max(t_all *all)
{
    if (all->stB.stack[0] > all->stA.stack[all->stA.len - 1])
    {
        ft_pa_move(all);
        ft_putstr("pa\n");
    }   
}

void    ft_insert(t_all *all)
{
    ft_insert_min(all);
    ft_insert_max(all);
}