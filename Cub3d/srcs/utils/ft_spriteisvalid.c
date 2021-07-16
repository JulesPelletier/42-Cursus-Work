/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spriteisvalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:42:19 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:48:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	ft_spriteisvalid(t_st *st, int i)
{
	if (i == '2')
		i = 0;
	else
		return (0);
	if (st->sprt.pathsprt[i] == NULL)
		return (0);
	return (1);
}
