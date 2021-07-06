/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_divider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:28:51 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 14:12:10 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_get_median(t_stack *stack)
{
    int     sum;
    int     i;

    i = 0;
    sum = 0;
    while (i < stack->len)
    {
        sum = sum + stack->stack[i];
        i++;
    }
    stack->params.median = sum / stack->len;
}

void    ft_get_divider(t_stack *stack)
{
    if (stack->len < 20)
        stack->params.chunck = 1;
    else if (stack->len <= 100 && stack->len >= 20)
        stack->params.chunck = 5;
    else if (stack->len > 100)
        stack->params.chunck = 11;
    stack->params.divider = (stack->params.max - stack->params.min)
         / stack->params.chunck;
    if (stack->params.divider / stack->params.median > 2)
        stack->params.divider = stack->params.median / stack->params.chunck;
}