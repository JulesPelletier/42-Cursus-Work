/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:47:10 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 14:06:06 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_init_operations(t_all *all)
{
    all->op.line = NULL;
}

void    ft_init_stack(t_all *all)
{
    all->stA.stack = NULL;
    all->stA.stack_aff = NULL;
    all->stA.init = 0;
    all->stA.len = 0;
    all->stB.stack = NULL;
    all->stB.stack_aff = NULL;
    all->stB.init = 0;
    all->stB.len = 0;
    ft_init_params(&all->stA);
    ft_init_params(&all->stB);
}

void    ft_init_params(t_stack *stack)
{
    stack->params.max = 0;
    stack->params.index_max = 0;
    stack->params.min = 0;
    stack->params.index_min = 0;
    stack->params.chunck = 0;
    stack->params.divider = 0;
    stack->params.pivot = 0;
    stack->params.median = 0;
}

void    ft_init_errors(t_all *all)
{
    all->err.nb_errors = 0;
    all->err.kill = 0;
}

void    ft_init_all(t_all *all)
{
    ft_init_stack(all);
    ft_init_errors(all);
    ft_init_operations(all);
}