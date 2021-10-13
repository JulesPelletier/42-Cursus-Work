/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:50:45 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/08 17:56:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_window(t_all *all)
{
	all->window.win_ptr = mlx_new_window(all->window.mlx_ptr,
			all->size * all->n_col,
			all->size * all->n_rows, "so_long");
}
