/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:07:53 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 11:23:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_entry_sort(t_all *all)
{
	if (ft_check_sort(all) == 1)
	{
		all->err.kill = 1;
		ft_putstr("OK\n");
		return (0);
	}
	else
		return (1);
}

void	test_d(t_all *all)
{
	if (ft_check_sort(all) != 1)
		ft_putstr("KO\n");
}

void	func(t_all *all)
{
	if (ft_check_sort(all) == 1)
	{
		all->err.kill = 1;
		ft_putstr("OK\n");
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	ft_init_all(&all);
	if (ac < 2)
		return (0);
	ft_fill_stack(&all, ac, av);
	if (check_entry_sort(&all) == 0)
		return (0);
	if (all.err.kill == 1 || ft_check_doublons(all.stA) == 0)
		ft_putstr("Error\n");
	while (all.err.kill == 0 && get_next_line(0, &all.op.line) > 0)
	{
		if (ft_check_operations(&all) != 1)
		{
			test_d(&all);
			return (0);
		}
		else
			ft_operation_apply(&all);
		func(&all);
	}
	test_d(&all);
	return (0);
}
