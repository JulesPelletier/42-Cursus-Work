/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:43:10 by Jules             #+#    #+#             */
/*   Updated: 2021/09/03 13:31:23 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (check_args(ac, av) < 0)
		return (0);
	else
	{
		init_all(&all);
		parse_params(&all, ac, av);
		show_struct(&all);
		//create_philos(&all);
		if (init_philo(&all));
		show_philos(&all);
	}
	return (0);
}