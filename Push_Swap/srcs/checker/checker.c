/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:52:44 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 11:26:59 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int ac, char **av)
{
	t_checker	all;

	all.ac_dup = ac;
	if (ac >= 2)
	{
		all.av_dup = all_char(ac, av, &all);
		checker_init(&all, 0);
		if (!all.stA.st || !doublon_int(&all.stA))
			ft_stop4("3", &all);
		all.stB.len = 0;
		ft_ch(&all, 0, createaction());
		free(all.stA.st);
		free(all.stB.st);
		if (all.flag[6])
			freechar(all.av_dup);
	}
	return (0);
}