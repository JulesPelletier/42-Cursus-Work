/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:46:14 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:56:45 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    algo_check(t_push_swap *all)
{
	init_stack(&all->stA);
	if (all->stA.len == 2)
		update_output(all, "sa");
	else if (all->stA.len == 3)
		algo_three(all);
	else if (all->stA.len <= 15)
		algo_quinze(all);
	else
		algo_quinze_plus(all);
}

int	main(int ac, char **av)
{
	t_push_swap	all;

	all.ac_dup = ac;
	if (all.ac_dup >= 2)
	{
		all.av_dup = all_char(ac, av, &all);
		all_init(all.av_dup, &all);
		if (!all.stA.st || !check_doublons(&all, &all.stA))
			ft_error("full", &all);
		all.stB.len = 0;
		if (is_sorted(&all) < 1)
			algo_check(&all);
		free(all.stA.st);
		free(all.stB.st);
		all.count_rrb = ft_clear2(&all);
		write(all.fd, all.str, all.count_rrb);
		free(all.str);
		if (all.flag[4])
			freechar(all.av_dup);
	}
	return (0);
}