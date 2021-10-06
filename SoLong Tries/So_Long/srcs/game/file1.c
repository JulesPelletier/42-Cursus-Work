/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:17:47 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 17:45:41 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int     handle_no_event(t_all *all)
{
    (void)all;
    return (0);
}

int     handle_input(t_all *all, int key)
{
    printf("Key Pressed : %d\n", key);
    if (key == 13)
    {
        all->keys.key_w = 1;
        show_keys(all);
    }
    return (0);
}

int     handle_output(t_all *all, int key)
{
    printf("Key Released : %d\n", key);
    if (key == 13)
    {
        all->keys.key_w = 0;
        show_keys(all);
    }
    return (0);
}

/*
int render(t_all *all)
{
    if (all->mlx.win_ptr != NULL)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2, COLOR_RED);
    return (0);
}
*/

void    draw(t_all *all, int i, int j, int cub)
{
    if (cub == 1)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, j, i, COLOR_RED);
    if (cub == 2)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, j, i, COLOR_GREEN);
    if (cub == 3)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, j, i, COLOR_YELLOW);
    if (cub == 4)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, j, i, COLOR_BLUE);
    if (cub == 5)
        mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr, j, i, COLOR_WHITE);
}

void    calculate_h_and_w(t_all *all)
{
    all->game.img_height = WIN_HEIGHT / all->params.len_x;
    all->game.img_width = WIN_WIDTH / all->params.len_y;
}

int test(t_all *all)
{
    int i;
    int j;
    int val1;
    int val2;

    i = 0;
    val1 = 0;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        val1 = i / all->game.img_height;
        val2 = 0;
        while (j < WIN_WIDTH && val1 < all->params.len_x && val2 < all->params.len_y)
        {
            val2 = j / all->game.img_width;
            //printf("Val 1 : %d | Val2 : %d\n", val1, val2);
            //printf("Map[%d] {%d} : %s\n", val1, val2, all->map.map[val1]);
            if (all->map.map[val1][val2] == '1')
                draw(all, i, j, 1);
            else if (all->map.map[val1][val2] == '0')
                draw(all, i, j, 2);
            else if (all->map.map[val1][val2] == 'C')
                draw(all, i, j, 3);
            else if (all->map.map[val1][val2] == 'E')
                draw(all, i, j, 4);
            else
                draw(all, i, j, 5);
            j++;
        }
        //printf("I : %d | J : %d | Val 1 : %d | Val2 : %d\n", i, j, val1, val2);
        i++;
    }
    return (0);
}

int render_big_square(t_all *all)
{
    int i;
    int j;

    if (all->mlx.win_ptr == NULL)
        return (1);
    i = 0;
    while (i < WIN_WIDTH)
    {
        j = 0;
        while (j < WIN_HEIGHT)
        {
            if (i < WIN_WIDTH / 2)
            {
                if (j < WIN_HEIGHT / 2)
                    draw(all, i, j, 1);
                else
                    draw(all, i, j, 2);
            }
            else
            {
                if (j < WIN_HEIGHT / 2)
                    draw(all, i, j, 3);
                else
                    draw(all, i, j, 4);
            }
            j++;
        }
        i++;
    }
    return (0);
}