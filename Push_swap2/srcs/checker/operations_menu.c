/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:39:11 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 17:54:55 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len <= 1)
		return ;
	temp = stack->st[stack->len - 2];
	stack->st[stack->len - 2] = stack->st[stack->len - 1];
	stack->st[stack->len - 1] = temp;
}

void	push(t_stack *s, t_stack *d)
{
	if (s->len <= 0)
		return ;
	if (s->len > 0)
	{
		d->st[d->len] = s->st[s->len - 1];
		d->len += 1;
		s->len -= 1;
	}
}

void	rotate(t_stack *s)
{
	int		temp;
	size_t	i;

	if (s->len <= 1)
		return ;
	i = s->len - 1;
	temp = s->st[i];
	while (i > 0)
	{
		s->st[i] = s->st[i - 1];
		i--;
	}
	s->st[i] = temp;
}

void	reverserotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack->len <= 1)
		return ;
	temp = stack->st[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->st[i] = stack->st[i + 1];
		i++;
	}
	stack->st[i] = temp;
}

void	ft_lecteur(char *inst, t_checker *all)
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
		return (reverserotate(&all->stA));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (reverserotate(&all->stB));
	reverserotate(&all->stA);
	reverserotate(&all->stB);
}