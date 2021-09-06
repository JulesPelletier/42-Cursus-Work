/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:49:28 by Jules             #+#    #+#             */
/*   Updated: 2021/09/01 14:13:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(char *str)
{
	int		i;

	i = 0;
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
	if (ac < 5)
	{
		write(2, "Not enough arguments : 5 needed\n", 33);
		return (-1);
	}
	if (ac > 6)
	{
		write(2, "Too many arguments : 5 needed\n", 31);
		return (-1);
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (check_numberofargs(ac) < 0)
		return (-1);
	else if (check_number(av[1]) < 0)
	{
		write(2, "First argument is not valid\n", 29);
		return (-1);
	}
	else if (check_number(av[2]) < 0)
	{
		write(2, "Second argument is not valid\n", 30);
		return (-1);
	}
	else if (check_number(av[3]) < 0)
	{
		write(2, "Third argument is not valid\n", 29);
		return (-1);
	}
	else if (check_number(av[4]) < 0)
	{
		write(2, "Fourth argument is not valid\n", 30);
		return (-1);
	}
	else if (check_number(av[5]) < 0)
	{
		write(2, "Fifth argument is not valid\n", 29);
		return (-1);
	}
	return (0);
}