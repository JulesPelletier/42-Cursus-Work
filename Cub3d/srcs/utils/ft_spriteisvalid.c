/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spriteisvalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:42:19 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:01 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int		ft_spriteisvalid(t_st *st, int i)
{
	if (i == '2')
		i = 0;
	else
		return (0);
	if (st->sprt.pathsprt[i] == NULL)
		return (0);
	return (1);
}
