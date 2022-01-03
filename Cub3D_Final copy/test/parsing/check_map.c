/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:44:05 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:08:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**convert_lst_map(t_all *all)
{
	t_list	*l_map;
	char	**map;
	int		size;
	int		i;

	size = ft_lstsize(all->map_ptr);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		free_parsing(all, NULL);
	map[size] = 0;
	l_map = all->map_ptr;
	i = 0;
	while (l_map)
	{
		map[i] = (char *)l_map->content;
		l_map = l_map->next;
		i++;
	}
	return (map);
}

void	final_check_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '_')
				map[i][j] = '0';
		}
	}
}

void	check_borders(t_all *all, char **map, int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0 || (size_t)(x + 1) == ft_strlen(map[y]) || map[y + 1] == 0)
	{
		free(map);
		free_parsing(all, NULL);
	}
	if (map[y][x - 1] == 32 || map[y][x + 1] == 32)
	{
		free(map);
		free_parsing(all, NULL);
	}
	if ((size_t)x < ft_strlen(map[y - 1]) && map[y - 1][x] == 32)
	{
		free(map);
		free_parsing(all, NULL);
	}
	check_limits(all, map, x, y);
}

void	check_rectangle(t_all *all, char **map, int x, int y)
{
	if (good_char(map[y][x]))
		map[y][x] = change_char(map[y][x]);
	check_borders(all, map, x, y);
	if (good_char(map[y][x - 1]))
		check_rectangle(all, map, x - 1, y);
	if (good_char(map[y][x + 1]))
		check_rectangle(all, map, x + 1, y);
	if ((size_t)x < ft_strlen(map[y - 1]))
	{
		if (good_char(map[y - 1][x]))
			check_rectangle(all, map, x, y - 1);
	}
	if ((size_t)x < ft_strlen(map[y + 1]))
	{
		if (good_char(map[y + 1][x]))
			check_rectangle(all, map, x, y + 1);
	}
}

void	check_mapline(t_all *all, int x, int y)
{
	char	**map;

	map = convert_lst_map(all);
	all->px = x;
	all->py = y;
	check_rectangle(all, map, x, y);
	final_check_map(map);
	free(map);
}