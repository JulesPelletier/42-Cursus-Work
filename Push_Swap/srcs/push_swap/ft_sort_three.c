/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:12:47 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 15:26:59 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     *ft_test_three(t_stack *stack, int *stack_dup, int a, int b, int c)
{
    
    stack_dup[0] = stack->stack[a];
    stack_dup[1] = stack->stack[b];
    stack_dup[2] = stack->stack[c];
    return (stack_dup);
}

void    ft_opti_three(t_all *all, t_stack *stack, int *stack_dup)
{
    if (ft_check_stack(ft_test_three(stack, stack_dup, 1, 0, 2), 3) == 1)
    {
        ft_sa_move(all);
        ft_putstr("sa\n");
    }
    else if (ft_check_stack(ft_test_three(stack, stack_dup, 2, 1, 0), 3) == 1)
    {
        ft_sa_move(all);
        ft_putstr("sa\n");
        ft_rra_move(all);
        ft_putstr("rra\n");
    }
    else if (ft_check_stack(ft_test_three(stack, stack_dup, 1, 2, 0), 3) == 1)
    {
        ft_ra_move(all);
        ft_putstr("ra\n");
    }
    else if (ft_check_stack(ft_test_three(stack, stack_dup, 0, 2, 1), 3) == 1)
    {
        ft_sa_move(all);
        ft_putstr("sa\n");
        ft_ra_move(all);
        ft_putstr("ra\n");
    }
    else if (ft_check_stack(stack->stack, 3) != 1)
    {
        ft_rra_move(all);
        ft_putstr("rra\n");
    }
}


void    ft_options_three(t_all *all, t_stack *stack)
{
    int     *stack_dup;

    if (!(stack_dup = malloc(sizeof(int) * 3)))
        ;
    ft_opti_three(all, stack, stack_dup);
}