/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:38:54 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 21:58:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	change_char(char c)
{
	if (c == '0')
		return ('_');
	return (c);
}

int	good_char(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

void	check_limits(t_all *all, char **map, int x, int y)
{
	if (((size_t)x >= ft_strlen(map[y - 1]) || (size_t)x >= ft_strlen(map[y + 1])) && \
		map[y][x] == '_')
	{
		free(map);
		free_parsing(all, NULL);
	}
}