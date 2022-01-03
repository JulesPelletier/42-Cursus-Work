/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:27:55 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:29:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**create_strs_tab(t_info *info)
{
	t_list	*ptr;
	char	**map;
	int		size;

	size = ft_lstsize(info->map_ptr);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		parsing_error(NULL, info, "error allocating the map\n");
	map[size] = 0;
	ptr = info->map_ptr;
	size = 0;
	while (ptr)
	{
		map[size] = (char *)ptr->content;
		ptr = ptr->next;
		size++;
	}
	return (map);
}

void	ff_rec(t_info *info, char **map, int x, int y)
{
	if (correct_char(map[y][x]))
		map[y][x] = change_char(map[y][x]);
	check_borders(info, map, x, y);
	if (correct_char(map[y][x - 1]))
		ff_rec(info, map, x - 1, y);
	if (correct_char(map[y][x + 1]))
		ff_rec(info, map, x + 1, y);
	if (x < ft_strlen(map[y - 1]))
	{
		if (correct_char(map[y - 1][x]))
			ff_rec(info, map, x, y - 1);
	}
	if (x < ft_strlen(map[y + 1]))
	{
		if (correct_char(map[y + 1][x]))
			ff_rec(info, map, x, y + 1);
	}
}

void	ff_check(t_info *info, int x, int y)
{
	char	**map;

	map = create_strs_tab(info);
	info->px = x;
	info->py = y;
	ff_rec(info, map, x, y);
	correct_map_char(map);
	free(map);
}

int	ft_is_good_mapchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == 32)
		i--;
	if (str[i] != '1')
		return (0);
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] != '1')
		return (0);
	while (*str)
	{
		if (*str != 32 && *str != '0' && *str != '1' && *str != 'N' \
			&& *str != 'S' && *str != 'E' && *str != 'W')
			return (0);
		str++;
	}
	return (1);
}

int	find_pos(char *str, t_info *info, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'W' || str[i] == 'S')
		{
			if (info->orientation)
				parsing_error(NULL, info, "there must be only one player\n");
			info->orientation = str[i];
			find_pos(str + i + 1, info, ret);
			return (i);
		}
		i++;
	}
	return (ret);
}
