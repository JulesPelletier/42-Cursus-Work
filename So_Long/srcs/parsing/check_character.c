/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:42:28 by Jules             #+#    #+#             */
/*   Updated: 2021/08/12 17:29:33 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int check_character(char c)
{
    if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
        return (-1);
    else
        return (1);
}

int check_map_char(t_all *all)
{
    int i;
    int j;

    i = 0;
    show_map(all);

    while (all->map.map[i] && i < all->params.len_x)
    {
        j = 0;
        while (all->map.map[i][j] && j < all->params.len_y)
        {
            if (check_character(all->map.map[i][j]) == -1)
            {
                errors_part1(4);
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (1);
}