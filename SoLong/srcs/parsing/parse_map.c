/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:56:32 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 17:39:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	count_cols(t_list *map)
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

static void	convert_map(t_all *all, t_list *list, t_list **error)
{
	int	i;

	i = 0;
	while (list)
	{
		all->map[i] = ft_strdup(list->content);
		i++;
		list = list->next;
	}
	ft_lstclear(&list, &free_map);
	i = -1;
	while (++i < all->n_rows)
		all->map[i] = add_spaces(all->map[i], all->n_col);
	check_borders(all, error);
	check_arguments(all, error);
}

int	count_grid(t_all *all, t_list *map, t_list **error)
{
	int	column;
	int	rows;

	column = count_cols(map);
	rows = ft_lstsize(map);
	if (!column || !rows)
	{
		add_error(all, error, "Map has 0 columns or 0 rows\n");
		return (0);
	}
	all->map = (char **)malloc(sizeof(char *) * rows + 1);
	all->n_col = column;
	all->n_rows = rows;
	convert_map(all, map, error);
	return (1);
}
