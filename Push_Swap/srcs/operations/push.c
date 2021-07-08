/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:56:00 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 11:43:10 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_fill_stack_1(t_stack *stack, t_stack *tmp, int i)
{
	while (i < stack->len)
	{
		tmp->stack[i] = stack->stack[i - 1];
		i++;
	}
}

void	ft_fill_stack_2(t_stack *stack, t_stack *tmp, int i)
{
	while (i < stack->len)
	{
		tmp->stack[i] = stack->stack[i + 1];
		i++;
	}
}

void	ft_pa_move(t_all *all)
{
	t_stack	tmpA;
	t_stack	tmpB;
	int		i;

	if (all->stB.len > 0)
	{
		all->stA.len = all->stA.len + 1;
		all->stB.len = all->stB.len - 1;
		tmpA.stack = malloc(sizeof(int) * all->stA.len + 1);
		if (tmpA.stack == NULL)
			;
		tmpA.stack[0] = all->stB.stack[0];
		i = 1;
		ft_fill_stack_1(&all->stA, &tmpA, i);
		all->stA.stack = tmpA.stack;
		tmpB.stack = malloc(sizeof(int) * all->stB.len + 1);
		if (tmpB.stack == NULL)
			;
		i = 0;
		ft_fill_stack_2(&all->stB, &tmpB, i);
		all->stB.stack = tmpB.stack;
	}
}

void	ft_pb_move(t_all *all)
{
	t_stack	tmpA;
	t_stack	tmpB;
	int		i;

	if (all->stA.len > 0)
	{
		all->stA.len = all->stA.len - 1;
		all->stB.len = all->stB.len + 1;
		tmpB.stack = malloc(sizeof(int) * all->stB.len + 1);
		if (tmpB.stack == NULL)
			;
		tmpB.stack[0] = all->stA.stack[0];
		i = 1;
		ft_fill_stack_1(&all->stB, &tmpB, i);
		all->stB.stack = tmpB.stack;
		tmpA.stack = malloc(sizeof(int) * all->stA.len + 1);
		if (tmpA.stack == NULL)
			;
		i = 0;
		ft_fill_stack_2(&all->stA, &tmpA, i);
		all->stA.stack = tmpA.stack;
	}
}
