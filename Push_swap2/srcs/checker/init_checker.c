/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:21:35 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:10:36 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	*init_stack(int ac, char **av, int count)
{
	int		*ptr;
	int		i;
	int		j;

	i = 1 + count;
	while (i < ac)
	{
		if (av[i][0] == 0 || !check_int(av[i]))
			return (0);
		i++;
	}
	if (ac - count < 2)
		return (0);
	ptr = malloc(sizeof(int) * ac - 1 - count);
	if (!(ptr))
		return (0);
	j = 0;
	i--;
	while (i > count)
		ptr[j++] = ft_atoi(av[i--]);
	return (ptr);
}

void	checker_init(t_checker *all, int i)
{
	while (i < 6)
		all->flag[i++] = 0;
	all->str = NULL;
	all->fd = 0;
	if (!check_options(all->ac_dup, all->av_dup, all, 1))
		ft_stop4("1", all);
	if (all->fd < 0)
		ft_stop4("1", all);
	all->stA.st = init_stack(all->ac_dup, all->av_dup, all->count);
	all->len = all->ac_dup - all->count - 1;
	all->stA.len = all->len;
	all->stB.st = malloc(sizeof(int) * all->stA.len);
	if (!(all->stB.st))
		ft_stop4("2", all);
}