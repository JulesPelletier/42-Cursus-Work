/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:17:45 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:20 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_coor(t_st *st)
{
	st->coor.currlvl = 0;
	st->coor.posx = 0;
	st->coor.posy = 0;
	st->coor.dirx = 0;
	st->coor.diry = 0;
	st->coor.olddirx = 0;
}
