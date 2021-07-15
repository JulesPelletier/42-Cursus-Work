/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:55:50 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:27:15 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free(t_st *st)
{
	ft_free_pars(st);
	ft_free_maps(st);
	ft_free_tex(st);
	ft_free_sprt(st);
	if (st->wall.tabwalldist != NULL)
		free(st->wall.tabwalldist);
}
