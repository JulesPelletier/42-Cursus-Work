/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:05:53 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 16:24:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	check_up_down(char **map, int j)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			flag = 1;
	i = -1;
	while (map[j - 1][++i])
		if (map[j - 1][i] != '1')
			flag = 1;
	return (flag);
}

static int	check_left_right(char **map, t_all *all)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < all->n_rows)
	{
		j = 0;
		if (map[i][j] != '1')
			flag = 1;
	}
	i = -1;
	while (++i < all->n_rows)
	{
		j = all->n_col - 1;
		if (map[i][j] != '1')
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
	flag += check_up_down(map, all->n_rows);
	flag += check_left_right(map, all);
	if (flag)
		add_error(all, error, "Map is not correctly closed at borders\n");
}
