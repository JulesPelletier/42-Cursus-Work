/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:13:46 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:54:59 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_stack *stack)
{
	int	temp;

	if (stack->len <= 1)
		return (0);
	temp = stack->st[stack->len - 2];
	stack->st[stack->len - 2] = stack->st[stack->len - 1];
	stack->st[stack->len - 1] = temp;
	stack->first = temp;
	stack_update(stack, 0);
	return (0);
}

int	push(t_stack *d, t_stack *s)
{
	int			*nst;
	size_t		i;

	if (s->len <= 0)
		return (0);
	if (d->flag == 1)
	{
		nst = malloc(sizeof(int) * (d->len + 1));
		if (!(nst))
			ft_error2("malloc");
		i = 0;
		while (i < d->len)
		{
			nst[i] = d->st[i];
			i++;
		}
		free(d->st);
		d->st = nst;
	}
	d->st[d->len] = s->st[s->len - 1];
	stack_update(s, -1);
	stack_update(d, 1);
	return (0);
}

int	rotate(t_stack *s)
{
	int			temp;
	size_t		i;

	if (s->len <= 1)
		return (0);
	i = s->len - 1;
	temp = s->st[i];
	while (i > 0)
	{
		s->st[i] = s->st[i - 1];
		i--;
	}
	s->st[0] = temp;
	stack_update(s, 0);
	return (0);
}

int	reverserotate(t_stack *stack)
{
	int			temp;
	size_t		i;

	if (stack->len <= 1)
		return (0);
	temp = stack->st[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->st[i] = stack->st[i + 1];
		i++;
	}
	stack->st[i] = temp;
	stack_update(stack, 0);
	return (0);
}

int	ft_lecteur(char *inst, t_push_swap *all)
{
	if (!ft_strncmp(inst, "sa", 2))
		return (swap(&all->stA));
	else if (!ft_strncmp(inst, "sb", 2))
		return (swap(&all->stB));
	else if (!ft_strncmp(inst, "pa", 2))
		return (push(&all->stA, &all->stB));
	else if (!ft_strncmp(inst, "ra", 2))
		return (rotate(&all->stA));
	else if (!ft_strncmp(inst, "rb", 2))
		return (rotate(&all->stB));
	else if (!ft_strncmp(inst, "pb", 2))
		return (push(&all->stB, &all->stA));
	else if (!ft_strncmp(inst, "rra", 3))
		return (reverserotate(&all->stA));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (reverserotate(&all->stB));
	else if (!ft_strncmp(inst, "rrr", 3))
	{
		reverserotate(&all->stA);
		return (reverserotate(&all->stB));
	}
	rotate(&all->stA);
	return (rotate(&all->stB));
}