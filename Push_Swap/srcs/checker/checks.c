/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:00:54 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:00:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	check_op(char *line, char **action)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(line, action[i], ft_strlen(line)))
			return (1);
		i++;
	}
	return (0);
}

int	check_int(char *nbr)
{
	char	*temp;
	int		fix;

	fix = 0;
	temp = ft_itoa(ft_atoi(nbr));
	if (ft_strncmp(temp, nbr, ft_strlen(nbr)))
	{
		if (nbr[fix] == '0')
		{
			free(temp);
			return (check_int(nbr + fix + 1));
		}
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	check_options(int ac, char **av, t_checker *all, int count2)
{
	all->count = 1;
	while (all->count < ac && av[all->count][0] == '-'
			&& !check_int(av[all->count]))
	{
		count2 = 1;
		while (av[all->count][count2])
		{
			if (av[all->count][count2] == 'c')
				all->flag[0] = 1;
			else if (av[all->count][count2] == 'v')
				all->flag[1] = 1;
			else if (av[all->count][count2] == 'e')
				all->flag[5] = 1;
			else
				return (0);
			count2++;
		}
		if (!all->str && all->flag[2] == 1 && all->count + 1 < ac)
			all->str = av[++all->count];
		else
			all->count++;
	}
	all->count = all->count - 1;
	return (1);
}

int	check_sorted(t_checker *all)
{
	size_t		i;

	i = 0;
	while (i < all->stA.len - 1)
	{
		if (all->stA.st[(int)i] < all->stA.st[(int)i + 1])
		{
			return (-1);
		}
		i++;
	}
	if (all->stB.len != 0)
		return (-2);
	return (1);
}

int	doublon_int(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < (int)stack->len)
	{
		j = i + 1;
		while (j < (int)stack->len)
		{
			if (stack->st[i] == stack->st[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
