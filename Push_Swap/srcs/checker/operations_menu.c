/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:39:11 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:01:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len <= 1)
		;
	temp = stack->st[stack->len - 2];
	stack->st[stack->len - 2] = stack->st[stack->len - 1];
	stack->st[stack->len - 1] = temp;
}

void	push(t_stack *stack1, t_stack *stack2)
{
	if (stack1->len <= 0)
		;
	if (stack1->len > 0)
	{
		stack2->st[stack2->len] = stack1->st[stack1->len - 1];
		stack2->len += 1;
		stack1->len -= 1;
	}
}

void	rotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack->len <= 1)
		;
	i = stack->len - 1;
	temp = stack->st[i];
	while (i > 0)
	{
		stack->st[i] = stack->st[i - 1];
		i--;
	}
	stack->st[i] = temp;
}

void	revrotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack->len <= 1)
		;
	temp = stack->st[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->st[i] = stack->st[i + 1];
		i++;
	}
	stack->st[i] = temp;
}

void	operations_menu(char *inst, t_checker *all)
{
	if (!ft_strncmp(inst, "sa", 3))
		return (swap(&all->stA));
	else if (!ft_strncmp(inst, "sb", 3))
		return (swap(&all->stB));
	else if (!ft_strncmp(inst, "pa", 3))
		return (push(&all->stB, &all->stA));
	else if (!ft_strncmp(inst, "ra", 3))
		return (rotate(&all->stA));
	else if (!ft_strncmp(inst, "rb", 3))
		return (rotate(&all->stB));
	else if (!ft_strncmp(inst, "rr", 3))
	{
		rotate(&all->stA);
		return (rotate(&all->stB));
	}
	else if (!ft_strncmp(inst, "pb", 3))
		return (push(&all->stA, &all->stB));
	else if (!ft_strncmp(inst, "rra", 3))
		return (revrotate(&all->stA));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (revrotate(&all->stB));
	revrotate(&all->stA);
	revrotate(&all->stB);
}
