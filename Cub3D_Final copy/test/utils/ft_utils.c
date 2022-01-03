/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:36:54 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 21:42:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_card(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'N')
		return (1);
	return (0);
}

int	ft_iswhite_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_check_char(char c)
{
	if (ft_is_card(c) || c == '0' || c == '1' || c == ' ')
		return (1);
	return (0);
}

int	ft_check_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_check_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	find_pos(t_all *all, char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'W' || str[i] == 'S')
		{
			if (all->orientation)
				free_parsing(all, NULL);
			all->orientation = str[i];
			find_pos(all, str + i + 1, ret);
			return (i);
		}
		i++;
	}
	return (ret);
}