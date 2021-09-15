/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:34:05 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 01:51:53 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_collectibles(t_all *all)
{
	int	i;
	int	j;

	all->collectibles = 0;
	all->exit = 0;
	i = 0;
	while (all->args.matrix[i])
	{
		j = 0;
		while (all->args.matrix[i][j])
		{
			if (all->args.matrix[i][j] == 'C')
				all->collectibles++;
			if (all->args.matrix[i][j] == 'E')
				all->exit++;
			j++;
		}
		i++;
	}
}

int	check_spaces(t_all *all, int i, int f)
{
	if (i - 1 < 0 || f - 1 < 0
		|| (f + 1 == (int)ft_strlen(all->args.matrix[i])))
		return (-1);
	if (check_charset(all->args.matrix[i - 1][f], "01PEC") == -1
		|| check_charset(all->args.matrix[i + 1][f], "01PEC") == -1
		|| check_charset(all->args.matrix[i][f - 1], "01PEC") == -1
		|| check_charset(all->args.matrix[i][f + 1], "01PEC") == -1)
		return (-1);
	return (0);
}

void	check_elems(t_all *all, int i, int f)
{
	if (check_closed(all) != 1)
		error(all, 1);
	if (check_charset(all->args.matrix[i][f], "10PCE") == -1)
		error(all, 1);
	if (all->args.matrix[i][f] == 'P')
	{
		all->map.player_count++;
		if (all->map.player_count > 1)
			all->args.matrix[i][f] = '0';
	}
	if (all->args.matrix[i][f] == 'C')
		all->map.sprite_count++;
	if (all->args.matrix[i][f] == 'E')
		all->map.exit_count++;
}

int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (i < 4)
		return (0);
	i -= 3;
	if (ft_strncmp(&file[i], ".ber", 4) != 0)
		return (0);
	return (1);
}

void	check_map(t_all *all)
{
	int	i;
	int	f;

	all->map.player_count = 0;
	all->map.sprite_count = 0;
	all->map.exit_count = 0;
	i = 0;
	if (check_closed(all) != 1)
		error(all, 1);
	while (all->args.matrix[i])
	{
		f = 0;
		while (all->args.matrix[i][f])
		{
			check_elems(all, i, f);
			f++;
		}
		if (i == 0)
			all->map.map_length = f;
		else if (f != all->map.map_length)
			error(all, 1);
		i++;
	}
	if (all->map.exit_count == 0 || all->map.player_count == 0
		|| all->map.sprite_count == 0)
		error(all, 1);
}