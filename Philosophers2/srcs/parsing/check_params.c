/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:49:28 by Jules             #+#    #+#             */
/*   Updated: 2021/12/03 11:55:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_exit("problem with string\n", 1));
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (ft_atoi(str));
	return (-1);
}

int	check_numberofargs(int ac)
{
	if (ac < 4)
		return (ft_exit("Not enough arguments : 4 or 5 needed\n", 1));
	if (ac > 6)
		return (ft_exit("Too many arguments : 4 or 5 needed\n", 1));
	return (0);
}

int	check_args(char **av)
{
	if (check_number(av[1]) < 0)
		return (ft_exit("First argument is not valid\n", 1));
	if (check_number(av[2]) < 0)
		return (ft_exit("Second argument is not valid\n", 1));
	if (check_number(av[3]) < 0)
		return (ft_exit("Third argument is not valid\n", 1));
	if (check_number(av[4]) < 0)
		return (ft_exit("Fourth argument is not valid\n", 1));
	if (av[5] && check_number(av[5]) < 0)
		return (ft_exit("Fifth argument is not valid\n", 1));
	return (0);
}

int		check_params(int ac, char **av)
{
	if (check_numberofargs(ac) < 0)
		return (-1);
	if (check_args(av) < 0)
		return (-1);
	return (0);
}

void	parse_params(t_all *all, int ac, char **av)
{
	all->params.n_philo = ft_atoi(av[1]);
	all->params.t_die = ft_atoi(av[2]);
	all->params.t_eat = ft_atoi(av[3]);
	all->params.t_sleep = ft_atoi(av[4]);
	if (av[5])
		all->params.n_loop = ft_atoi(av[ac - 1]);
	else
		all->params.n_loop = -1;
}