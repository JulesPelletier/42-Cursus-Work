/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:25:28 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 13:41:47 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int find_player(t_all *all)
{
    int i;
    int j;

    i = 0;
    while (i < all->params.len_x)
    {
        j = 0;
        while (j < all->params.len_y)
        {
            if (all->map.map[i][j] == 'P')
            {
                all->player.x = i;
                all->player.y = j;
            }
            j++;
        }
        i++;
    }
    return (1);
}

t_image	load_image(void *mlx, char *path)
{
	t_image	image;

	image.img = mlx_xpm_file_to_image(mlx, path, &(image.width), &(image.height));
	if (!image.img)
		return (image);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	return (image);
}

/*
void    load_image(t_image	image, void *mlx, char *path)
{
	image.img = mlx_xpm_file_to_image(mlx, path, &(image.width), &(image.height));
	if (!image.img)
        ;
	//image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
	//		&image.line_length, &image.endian);
}
*/

void    init_player_img(t_all *all)
{
    all->player.img_player = load_image(all->mlx.mlx_ptr,
			"./srcs/textures/nageuse1-fond-64-left-transp.xpm");
    all->player.img_player.img_link = ft_strdup("./srcs/textures/nageuse1-fond-64-left-transp.xpm");
}

void    fill_player(t_all *all)
{
    if (find_player(all) != 1)
        ;
    init_player_img(all);
}