/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:13:03 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:23:19 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	error_display(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\n1: Map is unvalid\n", 1);
	if (error == 3)
		ft_putstr_fd("Error\n3: Malloc Error\n", 1);
	if (error == 4)
		ft_putstr_fd("Error\n4: Too many players\n", 1);
	if (error == 5)
		ft_putstr_fd("Error\n5: Could not create bmp image\n", 1);
}

void	error(t_all *all, int e)
{
	int	i;

	if (e == 2)
	{
		ft_putstr_fd("Error\n2: Arguments invalid\n", 1);
		exit(1);
	}
	i = 0;
	while (all->args.matrix[i])
	{
		if (all->args.matrix[i])
			ft_free(all->args.matrix[i]);
		i++;
	}
	if (all->args.matrix)
		free(all->args.matrix);
	if (all->args.map)
		free(all->args.map);
	error_display(e);
	exit(1);
}