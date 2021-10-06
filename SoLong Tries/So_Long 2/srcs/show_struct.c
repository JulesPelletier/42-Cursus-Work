/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:17:28 by Jules             #+#    #+#             */
/*   Updated: 2021/09/01 10:48:14 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void    show_map(t_all *all)
{
    int i;

    i = 0;
    printf("======= [SHOW MAP] =======\n");
    while (i < all->params.len_x)
    {
        printf("Map [%d] : \t %s\n", i, all->map.map[i]);
        i++;
    }
}

int show_keys(t_all *all)
{
    printf("======= [SHOW KEYS] =======\n");
    printf("Key W : %d\n", all->keys.key_w);
    printf("Key A : %d\n", all->keys.key_a);
    printf("Key S : %d\n", all->keys.key_s);
    printf("Key D : %d\n", all->keys.key_d);
    printf("Key ESC : %d\n", all->keys.key_esc);
    return (0);
}

void    show_game(t_all *all)
{
    printf("======= [SHOW GAME] =======\n");
    printf("Start X : %d\n", all->game.start_x);
    printf("Start Y : %d\n", all->game.start_y);
    printf("Current X : %d\n", all->game.current_x);
    printf("Current Y : %d\n", all->game.current_y);
    printf("Collected : %d\n", all->game.collected);
    printf("Image Width : %d\n", all->game.img_width);
    printf("Image Height : %d\n", all->game.img_height);
}

void    show_player(t_all *all)
{
    printf("======= [SHOW PLAYER] =======\n");
    printf("Player X : %d\n", all->player.x);
    printf("Player Y : %d\n", all->player.y);
    printf("Smooth X : %f\n", all->player.smooth_x);
    printf("Smooth Y : %f\n", all->player.smooth_y);
    printf("Image link : %s\n", all->player.img_player.img_link);
    //printf("Player Address : %s\n", all->player.img_player.addr);
    printf("Player Bits per pixel : %d\n", all->player.img_player.bits_per_pixel);
    printf("Player Line length : %d\n", all->player.img_player.line_length);
    printf("Player endian : %d\n", all->player.img_player.endian);
    printf("Player width : %d\n", all->player.img_player.width);
    printf("Player height : %d\n", all->player.img_player.height);
    
}

void    show_collectibles(t_all *all)
{
    printf("======= [SHOW COLLECT] =======\n");
    printf("Collectibles Link : %s\n", all->collect.img_link);
    //printf("Collectibles Address : %s\n", all->collect.addr);
    printf("Collectibles Bits per pixel : %d\n", all->collect.bits_per_pixel);
    printf("Collectibles Line length : %d\n", all->collect.line_length);
    printf("Collectibles endian : %d\n", all->collect.endian);
    printf("Collectibles width : %d\n", all->collect.width);
    printf("Collectibles height : %d\n", all->collect.height);
}

void    show_exit(t_all *all)
{
    printf("======= [SHOW EXIT] =======\n");
    printf("Exit Link : %s\n", all->exit.img_link);
    //printf("Exit Address : %s\n", all->exit.addr);
    printf("Exit Bits per pixel : %d\n", all->exit.bits_per_pixel);
    printf("Exit Line length : %d\n", all->exit.line_length);
    printf("Exit endian : %d\n", all->exit.endian);
    printf("Exit width : %d\n", all->exit.width);
    printf("Exit height : %d\n", all->exit.height);
}

void    show_wall(t_all *all)
{
    printf("======= [SHOW WALL] =======\n");
    printf("Wall Link : %s\n", all->wall.img_link);
    printf("Wall Address : %s\n", all->wall.addr);
    printf("Wall Bits per pixel : %d\n", all->wall.bits_per_pixel);
    printf("Wall Line length : %d\n", all->wall.line_length);
    printf("Wall endian : %d\n", all->wall.endian);
    printf("Wall width : %d\n", all->wall.width);
    printf("Wall height : %d\n", all->wall.height);
}

void    show_floor(t_all *all)
{
    printf("======= [SHOW FLOOR] =======\n");
    printf("Floor Link : %s\n", all->floor.img_link);
    //printf("Floor Address : %s\n", all->floor.addr);
    printf("Floor Bits per pixel : %d\n", all->floor.bits_per_pixel);
    printf("Floor Line length : %d\n", all->floor.line_length);
    printf("Floor endian : %d\n", all->floor.endian);
    printf("Floor width : %d\n", all->floor.width);
    printf("Floor height : %d\n", all->floor.height);
}

void    show_struct(t_all *all)
{
    printf("======= [SHOW STRUCT] =======\n");
    printf("Len X : %d\n", all->params.len_x);
    printf("Len Y : %d\n", all->params.len_y);
    printf("Count exit : %d\n", all->params.count_exit);
    printf("Count starting pos : %d\n", all->params.count_starting_pos);
    printf("Count collect : %d\n", all->params.count_collect);
    printf("Flag map closed : %d\n", all->params.flag_map_closed);
    printf("Flag extension : %d\n", all->params.flag_extension);
    printf("Flag rectangular : %d\n", all->params.flag_rectangular);
    show_map(all);
    show_game(all);
    show_player(all);
    show_collectibles(all);
    show_exit(all);
    show_floor(all);
    show_wall(all);
    show_keys(all);
}