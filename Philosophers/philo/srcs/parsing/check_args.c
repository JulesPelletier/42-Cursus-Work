/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 05:03:00 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 05:10:06 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_number(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_exit("problem with string\n", 2));
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
		return (ft_exit("Not enough arguments : 4 or 5 needed\n", 2));
	if (ac > 6)
		return (ft_exit("Too many arguments : 4 or 5 needed\n", 2));
	return (0);
}

int	check_args(char **av)
{
	if (check_number(av[1]) <= 0)
		return (ft_exit("First argument is not valid\n", 2));
	if (check_number(av[2]) <= 0)
		return (ft_exit("Second argument is not valid\n", 2));
	if (check_number(av[3]) <= 0)
		return (ft_exit("Third argument is not valid\n", 2));
	if (check_number(av[4]) <= 0)
		return (ft_exit("Fourth argument is not valid\n", 2));
	if (av[5] && check_number(av[5]) <= 0)
		return (ft_exit("Fifth argument is not valid\n", 2));
	return (0);
}

int	check_params(int ac, char **av)
{
	if (check_numberofargs(ac) < 0)
		return (-1);
	if (check_args(av) < 0)
		return (-1);
	return (0);
}
