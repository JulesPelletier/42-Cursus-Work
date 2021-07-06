/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:56:00 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 15:49:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_pa_move(t_all *all)
{
    t_stack     tmpA;
    t_stack     tmpB;
    int         i;

    if (all->stB.len > 0)
    {
        all->stA.len = all->stA.len + 1;
        all->stB.len = all->stB.len - 1;
        if (!(tmpA.stack = malloc(sizeof(int) * all->stA.len + 1)))
            ;
        tmpA.stack[0] = all->stB.stack[0];
        i = 1;
        while (i < all->stA.len)
        {
            tmpA.stack[i] = all->stA.stack[i - 1];
            i++;
        }
        all->stA.stack = tmpA.stack;
        if (!(tmpB.stack = malloc(sizeof(int) * all->stB.len + 1)))
            ;
        i = 0;
        while (i < all->stB.len)
        {
            tmpB.stack[i] = all->stB.stack[i + 1];
            i++;
        }
        all->stB.stack = tmpB.stack;
    }
}

void    ft_pb_move(t_all *all)
{
    t_stack     tmpA;
    t_stack     tmpB;
    int         i;

    if (all->stA.len > 0)
    {
        all->stA.len = all->stA.len - 1;
        all->stB.len = all->stB.len + 1;
        if (!(tmpB.stack = malloc(sizeof(int) * all->stB.len + 1)))
            ;
        tmpB.stack[0] = all->stA.stack[0];
        i = 1;
        while (i < all->stB.len)
        {
            tmpB.stack[i] = all->stB.stack[i - 1];
            i++;
        }
        all->stB.stack = tmpB.stack;
        if (!(tmpA.stack = malloc(sizeof(int) * all->stA.len + 1)))
            ;
        i = 0;
        while (i < all->stA.len)
        {
            tmpA.stack[i] = all->stA.stack[i + 1];
            i++;
        }
        all->stA.stack = tmpA.stack;
    }
}