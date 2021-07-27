/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:02:39 by Jules             #+#    #+#             */
/*   Updated: 2021/07/26 17:48:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_update(t_stack *s, int i)
{
	size_t	count;

	count = 1;
	s->len = s->len + i;
	if (s->len == 0)
		return ;
	s->first = s->st[s->len - 1];
	s->second = s->st[0];
	s->min = s->second;
	s->max = s->second;
	while (count < s->len)
	{
		if (s->st[(int)count] > s->max)
			s->max = s->st[(int)count];
		if (s->st[(int)count] < s->min)
			s->min = s->st[(int)count];
		count++;
	}
}

void	update_output(t_push_swap *all, char *str)
{
	char		*str2;
	size_t		i;
	size_t		y;

	i = ft_strlen(all->str);
	str2 = malloc(sizeof(char) * (i + ft_strlen(str) + 3));
	if (!(str2))
		ft_error("4", all);
	i = 0;
	y = ft_strlen(all->str);
	while (i < y)
	{
		str2[i] = all->str[i];
		i++;
	}
	str2[i] = '\0';
	y = ft_lecteur(str, all);
	str = gestrr(all, str, str2);
	while (y < ft_strlen(str))
	{
		str2[i + y] = str[y];
		y++;
	}
	end_str(all, str2, i, y);
}

size_t  check_value(t_stack *stack, int n)
{
	size_t	i;

	i = 0;
	while (i < stack->len && stack->st[i] != n)
		i++;
	return (i);
}

int check_first_a(t_push_swap *all, int n)
{
	size_t	i;

	i = check_value(&all->stA, n);
	if (i == all->stA.len)
		return (0);
	if (i >= all->stA.len / 2)
	{
		while (all->stA.first != n)
			update_output(all, "ra");
	}
	else
	{
		while (all->stA.first != n)
			update_output(all, "rra");
	}
	return (1);
}

int check_first_b(t_push_swap *all, int n)
{
	size_t	i;

	i = check_value(&all->stB, n);
	if (i == all->stB.len)
		return (0);
	if (i >= all->stB.len / 2)
	{
		while (all->stB.first != n)
			update_output(all, "rb");
	}
	else
	{
		while (all->stB.first != n)
			update_output(all, "rrb");
	}
	return (1);
}