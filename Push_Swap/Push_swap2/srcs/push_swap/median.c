/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:27:51 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:54:44 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_inf(t_stack *s, size_t i, int value)
{
	size_t	count;

	count = 0;
	while (i < s->len)
	{
		if (s->st[i] < value)
			count++;
		i++;
	}
	return (count);
}


int	get_sup(t_stack *s, size_t i, int value)
{
	size_t	count;

	count = 0;
	while (i < s->len)
	{
		if (s->st[i] > value)
			count++;
		i++;
	}
	return (count);
}
int	get_median(t_stack *stack)
{
	size_t		imin;
	size_t		count;
	size_t		reststack;

	if (stack->fsort == 1)
		imin = check_value(stack, stack->min) + 1;
	else
		imin = 0;
	reststack = stack->len - imin;
	if (reststack == 1)
		return (stack->st[stack->len - 1]);
	count = imin;
	while (count < stack->len)
	{
		if (reststack % 2 == 1
			&& ((get_sup(stack, imin, stack->st[count]))
				== get_inf(stack, imin, stack->st[count])))
			break ;
		else if (get_inf(stack, imin, stack->st[count]) == get_sup(
				stack, imin, stack->st[count]) - 1)
			break ;
		count++;
	}
	return (stack->st[count]);
}