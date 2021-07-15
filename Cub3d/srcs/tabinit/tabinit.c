/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:24 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:31:30 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit(t_st *st)
{
	ft_tabinit_gettex(st);
	ft_tabinit_getsprt(st);
	ft_tabinit_distandorder(st);
	ft_tabinit_sprtval(st);
	ft_tabinit_getsprtval(st);
}
