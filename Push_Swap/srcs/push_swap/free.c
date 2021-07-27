/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:15:37 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:07:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	freechar(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	ft_clear(char *str, char *str2, int s)
{
	int		i;
	int		y;
	int		j;

	i = ft_strlen(str2) - s - 1;
	j = 0;
	while (i > 0)
	{
		if (ft_strncmp(str2 + i, str, s) == 0)
		{
			y = 0;
			while (y < s)
			{
				str2[y + i] = 'e';
				y++;
			}
			j++;
			return (1);
		}
		i--;
	}
	return (0);
}

int	ft_clear2(t_push_swap *all)
{
	size_t		i;
	size_t		y;
	char		*str;

	i = ft_strlen(all->str) - 1;
	str = malloc(sizeof(char) * (i + 2));
	if (!(str))
		ft_error("4", all);
	i = 0;
	y = 0;
	while (i < (ft_strlen(all->str)))
	{
		if (all->str[i] == 'e')
		{
			while (all->str[i] == 'e' || all->str[i] == '\n')
				i++;
		}
		str[y] = all->str[i];
		y++;
		i++;
	}
	str[y] = '\0';
	free(all->str);
	all->str = str;
	return (y);
}
