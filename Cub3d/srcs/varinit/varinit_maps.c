/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:34 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:37 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_maps(t_st *st)
{
	st->maps.nbrmaps = 0;
	st->maps.tabmaps = NULL;
	st->maps.tabmapval = NULL;
	st->maps.sizemapx = 0;
	st->maps.sizemapy = 0;
	st->maps.startset = 0;
}
