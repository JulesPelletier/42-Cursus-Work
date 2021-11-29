/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:43:10 by Jules             #+#    #+#             */
/*   Updated: 2021/11/29 15:06:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	all;

	memset(&all, 0, sizeof(t_all));
	if (check_params(ac, av) < 0)
		return (0);
	init_all(&all, ac, av);
	//show_all(&all);
	if (start_loop(&all))
		return (clean_threads(&all));
	return (0);
}