/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:19:15 by Jules             #+#    #+#             */
/*   Updated: 2021/08/18 17:42:59 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_images(t_all *all)
{
    init_image(&all->collect);
    init_image(&all->floor);
    init_image(&all->exit);
    init_image(&all->wall);
}