/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:35 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:13:48 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map(t_all *all)
{
	int		i;
	int		j;
	t_list	*map;

	i = -1;
	j = -1;
	if (ft_lstsize(all->map_ptr) < 3)
		free_parsing(all, NULL);
	map = all->map_ptr;
	while (map)
	{
		if (j == -1)
			i++;
		if (ft_check_string((char *)map->content))
			free_parsing(all, NULL);
		j = find_pos(all, (char *)map->content, j);
		map = map->next;
	}
	if (j == -1)
		free_parsing(all, NULL);
	check_mapline(all, j, i);
}


void	check_parsing(t_all *all)
{
	printf("Check before\n");
	if (!all->tex->no_texture || !all->tex->we_texture \
		|| !all->tex->so_texture || !all->tex->ea_texture)
		free_parsing(all, NULL);
	if (!all->tex->no_texture->texture || !all->tex->we_texture->texture \
		|| !all->tex->so_texture->texture || !all->tex->ea_texture->texture)
		free_parsing(all, NULL);
	printf("Check after\n");
	check_map(all);
	
}