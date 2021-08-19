/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@alludent.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:16:25 by Jules             #+#    #+#             */
/*   Updated: 2021/08/12 12:16:35 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    init_mlx(t_all *all)
{
    all->mlx.mlx_ptr = NULL;
	all->mlx.win_ptr = NULL;
	all->mlx.img_ptr = NULL;
	all->mlx.img_data = NULL;
	all->mlx.img_bpp = 0;
	all->mlx.img_sl = 0;
	all->mlx.img_end = 0;
}