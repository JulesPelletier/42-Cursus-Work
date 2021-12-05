/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:48:55 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/05 17:26:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_all all;

	if (!(ft_parse(ac, av, &all.params)))
		return (0);
	all.philos = malloc(sizeof(t_philo) * all.params.n_philo);
	if (all.philos == NULL)
		return (ft_exit("Philos malloc failed", 1));

	if (!init_loop(&all) || !loop(&all))
	{
		free(all.philos);
		return (0);
	}
	end_loop(&all);
}
