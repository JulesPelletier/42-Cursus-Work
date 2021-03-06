/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:32:50 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:27:52 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_rotationleft(t_st *st)
{
	st->coor.olddirx = st->coor.dirx;
	st->coor.dirx = st->coor.dirx * cos(st->spd.rotspeed)
		- st->coor.diry * sin(st->spd.rotspeed);
	st->coor.diry = st->coor.olddirx * sin(st->spd.rotspeed)
		+ st->coor.diry * cos(st->spd.rotspeed);
	st->rayc.oldplanex = st->rayc.planex;
	st->rayc.planex = st->rayc.planex * cos(st->spd.rotspeed)
		- st->rayc.planey * sin(st->spd.rotspeed);
	st->rayc.planey = st->rayc.oldplanex * sin(st->spd.rotspeed)
		+ st->rayc.planey * cos(st->spd.rotspeed);
}

void	ft_keys_rotationright(t_st *st)
{
	st->coor.olddirx = st->coor.dirx;
	st->coor.dirx = st->coor.dirx * cos(-st->spd.rotspeed)
		- st->coor.diry * sin(-st->spd.rotspeed);
	st->coor.diry = st->coor.olddirx * sin(-st->spd.rotspeed)
		+ st->coor.diry * cos(-st->spd.rotspeed);
	st->rayc.oldplanex = st->rayc.planex;
	st->rayc.planex = st->rayc.planex * cos(-st->spd.rotspeed)
		- st->rayc.planey * sin(-st->spd.rotspeed);
	st->rayc.planey = st->rayc.oldplanex * sin(-st->spd.rotspeed)
		+ st->rayc.planey * cos(-st->spd.rotspeed);
}
