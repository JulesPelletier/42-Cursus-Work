/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:13:45 by Jules             #+#    #+#             */
/*   Updated: 2021/08/18 17:21:09 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_all(t_all *all)
{
    init_params(all);
    init_map(all);
    init_game(all);
    init_mlx(all);
    init_keys(all);
    init_player(all);
    init_images(all);
    init_draw(all);
}