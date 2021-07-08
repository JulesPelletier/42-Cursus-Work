/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:10:36 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 11:18:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_show_2stacks(t_stack stack1, t_stack stack2)
{
	int	i;

	i = 0;
	printf("----------------------\n\n");
	printf(" TAB 1 \t TAB 2 \n\n");
	while (i < stack1.len)
	{
		printf("   %d \t   %d \n", stack1.stack[i], stack2.stack[i]);
		i++;
	}
	printf("   - \t   - \n");
}

void	ft_show_2stacks_char(t_stack stack1, t_stack stack2)
{
	int	i;

	i = 0;
	printf("----------------------\n\n");
	printf(" TAB 1 \t TAB 2 \n\n");
	while (i < ft_max(stack1.len, stack2.len))
	{
		printf("   ");
		if (i < stack1.len)
			printf("%s\t", ft_itoa(stack1.stack[i]));
		else if (i >= stack1.len)
			printf(" \t");
		if (i < stack2.len)
			printf("   %s\t\n", ft_itoa(stack2.stack[i]));
		else if (i >= stack2.len)
			printf(" \t\n");
		i++;
	}
	printf("   - \t   - \n");
}
