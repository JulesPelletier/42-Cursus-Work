/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:28:43 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 13:29:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	ft_exit_killmlx(t_st *st)
{
	ft_varinit(st);
	exit(-1);
	return (0);
}

void	ft_exit(t_st *st, int ret)
{
	ft_free(st);
	if (st->mlx.mlx_ptr && !st->mlx.win_ptr)
	{
		mlx_loop_hook(st->mlx.mlx_ptr, ft_exit_killmlx, &st);
		mlx_loop(st->mlx.mlx_ptr);
	}
	else
	{
		ft_varinit(st);
		exit(ret);
	}
}
