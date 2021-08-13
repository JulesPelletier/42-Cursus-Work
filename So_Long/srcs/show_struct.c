/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:17:28 by Jules             #+#    #+#             */
/*   Updated: 2021/08/13 13:52:53 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void    show_map(t_all *all)
{
    int i;

    i = 0;
    printf("LEN X : %d\n", all->params.len_x);
    while (i < all->params.len_x)
    {
        printf("Map [%d] : \t %s\n", i, all->map.map[i]);
        i++;
    }
}

int show_keys(t_all *all)
{
    printf("Key W : %d\n", all->keys.key_w);
    printf("Key A : %d\n", all->keys.key_a);
    printf("Key S : %d\n", all->keys.key_s);
    printf("Key D : %d\n", all->keys.key_d);
    printf("Key ESC : %d\n", all->keys.key_esc);
    return (0);
}

void    show_struct(t_all *all)
{
    printf("Len X : %d\n", all->params.len_x);
    printf("Len Y : %d\n", all->params.len_y);
    printf("Count exit : %d\n", all->params.count_exit);
    printf("Count starting pos : %d\n", all->params.count_starting_pos);
    printf("Count collect : %d\n", all->params.count_collect);
    printf("Flag map closed : %d\n", all->params.flag_map_closed);
    printf("Flag extension : %d\n", all->params.flag_extension);
    printf("Flag rectangular : %d\n", all->params.flag_rectangular);
    printf("\n === MAP === \n");
    show_map(all);
}