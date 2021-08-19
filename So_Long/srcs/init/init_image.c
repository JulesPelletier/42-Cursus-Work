/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:52:58 by Jules             #+#    #+#             */
/*   Updated: 2021/08/18 17:25:44 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_image(t_image *image)
{
    image->img_link = NULL;
    image->img = NULL;    
    image->addr = NULL;
    image->bits_per_pixel = 0;
    image->line_length = 0;
    image->endian = 0;
    image->width = 0;
    image->height = 0;
}