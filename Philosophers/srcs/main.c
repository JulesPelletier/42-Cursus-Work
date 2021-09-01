/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:43:10 by Jules             #+#    #+#             */
/*   Updated: 2021/08/31 16:08:30 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_all all;

	if (ac == 6)
	{
		init_params(&all);
		parse_params(&all, ac, av);
		show_struct(&all);
		create_philos(&all);
		show_philos(&all);
	}
	else
		printf("Number of arguments incorrect\n");
	return (0);
}