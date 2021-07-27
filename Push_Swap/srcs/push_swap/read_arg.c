/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:28:53 by Jules             #+#    #+#             */
/*   Updated: 2021/07/24 17:54:51 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *read_arg(int ac, char **av, int n)
{
	int		*tmp;
	int		i;
	int		j;

	i = 1 + n;
	while (i < ac)
	{
		if (av[i][0] == 0 || !check_int(av[i]))
			return (0);
		i++;
	}
	if (ac - n < 2)
		return (0);
	tmp = malloc(sizeof(int) * ac - 1 - n);
	if (!(tmp))
		return (0);
	j = 0;
	i--;
	while (i > n)
		tmp[j++] = ft_atoi(av[i--]);
	return (tmp);
}