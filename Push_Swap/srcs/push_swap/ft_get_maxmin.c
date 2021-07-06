/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maxmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:11:10 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 12:31:12 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_get_max(t_stack *stack)
{
    int     i;
    int     max;
    int     index_max;

    i = 0;
    index_max = 0;
    max = stack->stack[0];
    while (i < stack->len)
    {
        if (stack->stack[i] > max)
        {
            max = stack->stack[i];
            index_max = i;
        }
         i++;
    }
    stack->params.max = max;
    stack->params.index_max = index_max;
}

void    ft_get_min(t_stack *stack)
{
    int     i;
    int     min;
    int     index_min;

    i = 0;
    index_min = 0;
    min = stack->stack[0];
    while (i < stack->len)
    {
        if (stack->stack[i] < min)
        {
            min = stack->stack[i];
            index_min = i;
        }
        i++;
    }
    stack->params.min = min;
    stack->params.index_min = index_min;
}