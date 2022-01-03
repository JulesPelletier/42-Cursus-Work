/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:33:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:10:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	show_struct(t_all *all)
{
	printf("Texture 1 : %s\n", (char *)all->tex->no_texture->texture);
	printf("Texture 2 : %s\n", (char *)all->tex->so_texture->texture);
	printf("Texture 3 : %s\n", (char *)all->tex->ea_texture->texture);
	printf("Texture 4 : %s\n", (char *)all->tex->we_texture->texture);
}

void	cub3d(char **av)
{
	t_all *all;

	all = ft_parse(av[1]);
	show_struct(all);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		cub3d(av);
	else
		ft_putstr_fd("Error : ./cub3d <map.cub>\n", 2);
}