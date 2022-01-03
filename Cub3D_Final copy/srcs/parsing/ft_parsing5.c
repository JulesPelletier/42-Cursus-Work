/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:53 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:30:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_max(t_info *info)
{
	t_list	*ptr;
	int		max;

	ptr = info->map_ptr;
	max = 0;
	while (ptr)
	{
		max = (int)fmax(max, ft_strlen((char *)ptr->content));
		ptr = ptr->next;
	}
	return (max);
}

void	correct_map_char(char **map)
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

char	change_char(char c)
{
	if (c == '0')
		return ('_');
	return (c);
}

int	correct_char(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

void	check_borders(t_info *info, char **map, int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0 || x + 1 == ft_strlen(map[y]) || map[y + 1] == 0)
	{
		free(map);
		parsing_error(NULL, info, "map open\n");
	}
	if (map[y][x - 1] == 32 || map[y][x + 1] == 32)
	{
		free(map);
		parsing_error(NULL, info, "map open\n");
	}
	if (x < ft_strlen(map[y - 1]) && map[y - 1][x] == 32)
	{
		free(map);
		parsing_error(NULL, info, "map open\n");
	}
	check_limits(info, map, x, y);
}