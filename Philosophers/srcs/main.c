/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:43:10 by Jules             #+#    #+#             */
/*   Updated: 2021/09/07 18:32:52 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	all;

	memset(&all, 0, sizeof(t_all));
	if (check_params(ac, av) < 0)
		return (0);
	init_all(&all);
	parse_params(&all, ac, av);
	show_game(&all);
	show_struct(&all);
	//create_philos(&all);
	if (init_philo(&all))
		return (0);
	show_philos(&all);
	thread_init(&all);
	show_all(&all);
	return (0);
}