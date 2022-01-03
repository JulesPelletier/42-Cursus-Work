/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:33:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:29:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub3d(char **av)
{
	t_info *info;

	info = ft_parsing(av[1]);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		cub3d(av);
	else
		ft_putstr_fd("Error : ./cub3d <map.cub>\n", 2);
}