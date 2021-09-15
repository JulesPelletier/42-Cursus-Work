/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:30:40 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_clean(t_all *all)
{
	int	i;

	i = 0;
	while (all->args.matrix[i])
	{
		if (all->args.matrix[i])
			ft_free(all->args.matrix[i]);
		i++;
	}
	if (all->args.matrix)
		free(all->args.matrix);
	clear_images(all);
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	//if (all->mlx.ptr)
	//	mlx_destroy_display(all->mlx.ptr);
	if (all->mlx.ptr)
		free(all->mlx.ptr);
	exit(0);
	return (0);
}