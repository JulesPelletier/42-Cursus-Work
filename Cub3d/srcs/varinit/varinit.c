/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:29:10 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:33:29 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit(t_st *st)
{
	ft_varinit_pars(st);
	ft_varinit_maps(st);
	ft_varinit_mlx(st);
	ft_varinit_tex(st);
	ft_varinit_sprt(st);
	ft_varinit_win(st);
	ft_varinit_coor(st);
	ft_varinit_spd(st);
	ft_varinit_rayc(st);
	ft_varinit_wall(st);
	ft_varinit_draw(st);
	ft_varinit_keys(st);
}
