/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:16:39 by Jules             #+#    #+#             */
/*   Updated: 2021/07/24 17:49:49 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     check_int(char *str)
{
	char	*temp;
	int		fix;

	fix = 0;
	if (str[0] == '-')
		fix = 1;
	temp = ft_itoa(ft_atoi(str));
	if (ft_strncmp(temp, str, ft_strlen(str)))
	{
		if (str[fix] == '0')
		{
			free(temp);
			return (check_int(str + fix + 1));
		}
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int     check_options(t_push_swap *all, int ac, char **av, int i)
{
	int		count2;

	while (i < ac && av[i][0] == '-' && !check_int(av[i]))
	{
		count2 = 1;
		while (av[i][count2])
		{
			if (av[i][count2] == 'c')
				all->flag[0] = 1;
			else if (av[i][count2] == 'v')
				all->flag[1] = 1;
			else if (av[i][count2] == 'f')
				all->flag[2] = 1;
			else
				return (0);
			count2++;
		}
		if (!all->str && all->flag[2] == 1 && i + 1 < ac)
			all->str = av[++i];
		else
			i++;
	}
	all->count = i - 1;
	return (1);
}

int check_doublons(t_push_swap *all, t_stack *stack)
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
				ft_error("3", all);
			j++;
		}
		i++;
	}
	return (1);
}


int	check_borne(t_stack *stack, int min, int max)
{
	size_t	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->st[i] >= min && stack->st[i] <= max)
			return (1);
		i++;
	}
	return (0);
}