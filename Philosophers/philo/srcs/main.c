/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:39:29 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 06:30:45 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (parsing(&(all.params), ac, av))
		return (write(1, "Parsing failed\n", 21));
	if (all.params.must_eat && !all.params.n_loop)
		return (0);
	if (init_loop(&all))
		return (free_philos(&all));
	loop(&all, 0);
	free_philos(&all);
	return (0);
}
