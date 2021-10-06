/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:41:57 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 17:40:13 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i -= 4;
	if (i > 0)
		return (ft_strequ(&str[i], ".ber"));
	else
		return (0);
}

int	check_args(t_all *all, int argc, char *str, t_list **error)
{
	if (argc != 2)
	{
		add_error(all, error, "There must be 2 arguments\n");
		return (1);
	}
	else if (!check_extension(str))
	{
		add_error(all, error, "Is not a '.ber' file\n");
		return (1);
	}
	return (0);
}

static void	check_number_args(t_all *all, t_list **error)
{
	if (all->collectible < 1)
		add_error(all, error, "You have less than 1 collection in the map\n");
	if (all->start < 1)
		add_error(all, error, "You have less than 1 player in the map\n");
	if (all->exit < 1)
		add_error(all, error, "You have less than 1 exit in the map\n");
	if (all->start > 1)
		add_error(all, error, "You have more than 1 player in the map\n");
}

void	check_arguments(t_all *all, t_list **error)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->n_rows)
	{
		j = -1;
		while (++j < all->n_col)
		{
			if (all->map[i][j] == 'C')
				all->collectible += 1;
			else if (all->map[i][j] == 'E')
				all->exit += 1;
			else if (all->map[i][j] == 'P')
			{
				all->start += 1;
				all->player.x = i;
				all->player.y = j;
			}
		}
	}
	check_number_args(all, error);
}
