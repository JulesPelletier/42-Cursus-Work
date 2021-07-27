/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:42:26 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:04:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**malloqueur(char **av)
{
	int		i;
	int		j;
	int		k;
	char	**av2;

	i = 0;
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				k++;
			j++;
		}
		i++;
		k++;
	}
	k++;
	av2 = malloc(sizeof(char *) * k);
	if (!av2)
		exit (1);
	av2[k - 1] = NULL;
	return (av2);
}

char	**replace(char **av, t_push_swap *all)
{
	int		i;
	int		j;
	int		k;
	char	**av3;
	char	**av2;

	all->count = 0;
	j = 0;
	av2 = malloqueur(av);
	i = 0;
	while (av[i])
	{
		av3 = ft_split(av[i], ' ');
		k = 0;
		while (av3[k])
		{
			av2[j] = av3[k];
			j++;
			k++;
		}
		free(av3);
		i++;
	}
	return (av2);
}

char	**ft_show(char **str, t_push_swap *all)
{
	int	i;

	i = 0;
	all->flag[4] = 1;
	while (str[i])
		i++;
	all->ac_dup = i;
	return (str);
}

char	**all_char(int ac, char **av, t_push_swap *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all->flag[4] = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				return (ft_show(replace(av, all), all));
			}
			j++;
		}
		i++;
	}
	all->ac_dup = ac;
	return (av);
}
