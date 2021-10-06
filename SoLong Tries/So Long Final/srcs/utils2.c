/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:46:43 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:49:38 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	record_map(char *line, t_list **list)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
}

char	*add_spaces(char *str, int largest_line)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char *) * largest_line + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < largest_line)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

void	init_ptr_mlx(t_all *all)
{
	all->mlx.mlx_ptr = mlx_init();
}

void	load_map(t_all *all)
{
	init_ptr_mlx(all);
	load_image(all);
	//load_window(all);
	get_textures(all);
	mlx_hook(all->mlx.win_ptr, 3, 1L << 1, key_release, &all->player);
	mlx_hook(all->mlx.win_ptr, 2, 1L << 0, key_press, all);
	mlx_loop_hook(all->mlx.mlx_ptr, ft_display, all);
	mlx_hook(all->mlx.win_ptr, 33, 1L << 17, &end_game, all);
	mlx_loop(all->mlx.mlx_ptr);
}