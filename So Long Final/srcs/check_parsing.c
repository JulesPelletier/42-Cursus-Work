/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:46:58 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:21:56 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int		check_extension(char *str)
{
	int		i;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".ber", ft_strlen(&str[i])) == 0)
		return (1);
	else
		return (0);
}

int		check_arguments(t_all *all, int ac, char *file, t_list **error)
{
	if (ac < 2)
	{
		add_error(all, error, "Not enough arguments : ./[exec_name][file_name]\n");
		return (-1);
	}
	else if (ac > 2)
	{
		add_error(all, error, "Too many arguments : ./[exec_name][file_name]\n");
		return (-1);
	}
	else if (!check_extension(file))
	{
		add_error(all, error, "Wrong extension : '.ber' needed\n");
		return (-1);
	}
	return (0);
}

int	check_lines(t_all *all)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (all->map[0][++i])
		if (all->map[0][i] != '1')
			flag = 1;
	i = -1;
	while (all->map[all->params.n_rows - 1][++i])
		if (all->map[all->params.n_rows - 1][i] != '1')
			flag = 1;
	return (flag);
}

int	check_columns(t_all *all)
{
	int	i;
	int	j;
	int flag;

	flag = 0;
	i = -1;
	while (++i < all->params.n_rows)
	{
		j = 0;
		if (all->map[i][j] != '1')
			flag = 1;
		j = all->params.n_columns - 1;
		if (all->map[i][j] != '1')
			flag = 1;
	}
	return (flag);
}

void	check_borders(t_all *all, t_list **error)
{
	int		flag;
	char	**map;

	flag = 0;
	map = all->map;
	flag += check_lines(all);
	flag += check_columns(all);
	if (flag > 0)
		add_error(all, error, "Map is not closed properly\n");
}