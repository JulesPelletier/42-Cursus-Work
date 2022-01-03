/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:44:05 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 17:11:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_allocation(t_all *all)
{
	if (!all)
		ft_exit("Error : malloc failed\n");
}

void	check_file(t_all *all, char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size < 4 || ft_strncmp(file + (size - 4), ".cub", 4))
	{
		free_all(all);
		ft_exit("Error : file extension\n");
	}
}

unsigned char	check_color(t_all *all, char *line, int i)
{
	int res;

	res = ft_atoi(line + i);
	if (res < 0 || res > 255)
		free_parsing(all, line);
	return (res);
}