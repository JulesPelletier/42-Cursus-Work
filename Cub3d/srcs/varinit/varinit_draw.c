/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:27:34 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:25 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_draw(t_st *st)
{
	st->draw.lineheight = 0;
	st->draw.drawstart = 0;
	st->draw.drawend = 0;
	st->draw.color = 0;
}
