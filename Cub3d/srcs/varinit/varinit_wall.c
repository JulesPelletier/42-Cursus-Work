/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:25:22 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:33:18 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_wall(t_st *st)
{
	st->wall.hit = 0;
	st->wall.side = 0;
	st->wall.walldist = 0;
	st->wall.tabwalldist = NULL;
	st->wall.wallx = 0;
}
