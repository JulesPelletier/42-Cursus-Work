/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:22:15 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 16:56:38 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     ft_check_stack(int *stack, int len)
{
    int     i;

    i = 0;

    while ((i < len) && (i + 1 < len))
    {
        if (stack[i] > stack[i + 1])
            return (0);
        else
            i++;
    }
    return (1);
}

int     ft_check_stack_desc(int *stack, int len)
{
    int     i;

    i = 0;

    while ((i < len) && (i + 1 < len))
    {
        if (stack[i] < stack[i + 1])
            return (0);
        else
            i++;
    }
    return (1);
}