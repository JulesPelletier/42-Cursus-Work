/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:30:29 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:24:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cub3d(char **av)
{
	t_info	*info;

	info = ft_parsing(av[1]);
	//ft_launch_game(info);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_cub3d(av);
	else
		ft_putstr_fd("Error\nusage : ./cub3D *.cub\n", 2);
	return (0);
}