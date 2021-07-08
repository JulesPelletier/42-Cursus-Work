/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:46:11 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 11:00:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_malloc_stack(t_all *all)
{
	all->stA.stack = malloc(sizeof(int) * all->stA.len + 1);
	if (all->stA.stack == NULL)
		;
	all->stB.stack = malloc(sizeof(int) * all->stA.len + 1);
	if (all->stB.stack == NULL)
		;
	all->stA.stack_aff = malloc(sizeof(char *) * all->stA.len + 1);
	if (all->stA.stack_aff == NULL)
		;
	all->stB.stack_aff = malloc(sizeof(char *) * all->stA.len + 1);
	if (all->stB.stack_aff == NULL)
		;
	ft_zero_stack(all);
}

void	ft_free_stack(t_stack stack)
{
	free(stack.stack);
	free(stack.stack_aff);
	stack.stack_aff = NULL;
}

void	ft_zero_stack(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->stA.len)
	{
		all->stA.stack[i] = 0;
		all->stB.stack[i] = 0;
		all->stA.stack_aff[i] = " ";
		all->stB.stack_aff[i] = " ";
		i++;
	}
}

int	ft_check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_stack(t_all *all, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_check_int(av[i]) == 1
			&& ft_atoi(av[i]) >= INT_MIN
			&& ft_atoi(av[i]) <= INT_MAX)
			all->stA.len++;
		else
			all->err.kill = 1;
		i++;
	}
	ft_malloc_stack(all);
	i = 0;
	while (i < all->stA.len)
	{
		all->stA.stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
}
