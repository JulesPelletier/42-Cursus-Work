/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:11:54 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:23:47 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	count_columns(t_list *map)
{
	int	max;
	int	i;

	max = 0;
	while (map)
	{
		i = ft_strlen(map->content);
		if (i > max)
			max = i;
		map = map->next;
	}
	return (max);
}

void	check_n_arguments(t_all *all, t_list **error)
{
	if (all->params.collectibles < 1)
		add_error(all, error, "Not enough collectibles\n");
	if (all->params.exits < 1)
		add_error(all, error, "Not enough exits\n");
	if (all->params.start < 1)
		add_error(all, error, "No starting position\n");
	if (all->params.start > 1)
		add_error(all, error, "More than one starting position\n");
}

void	check_args(t_all *all, t_list **error)
{
	int	i;
	int	j;

	i = -1;
	while(++i < all->params.n_rows)
	{
		j = -1;
		while (++j < all->params.n_columns)
		{
			if (all->map[i][j] == 'C')
				all->params.collectibles += 1;
			else if (all->map[i][j] == 'E')
				all->params.exits += 1;
			else if (all->map[i][j] == 'P')
				all->params.start += 1;
		}
	}
	check_n_arguments(all, error);
}

void	convert_map(t_all *all, t_list *map, t_list **error)
{
	int	i;

	i = 0;
	while (map)
	{
		all->map[i] = ft_strdup(map->content);
		i++;
		map = map->next;
	}
	i = -1;
	while (++i < all->params.n_rows)
		all->map[i] = add_spaces(all->map[i], all->params.n_columns);
	check_borders(all, error);
	check_args(all, error);
}

int	create_map(t_all *all, t_list *map, t_list **error)
{
	int	columns;
	int	rows;

	columns = count_columns(map);
	rows = ft_lstsize(map);
	if (columns < 3 || rows < 3)
	{
		add_error(all, error, "Impossible map\n");
		return (0);
	}
	all->map = (char **)malloc(sizeof(char *) * rows + 1);
	all->params.n_columns = columns;
	all->params.n_rows = rows;
	convert_map(all, map, error);
	return (1);
}