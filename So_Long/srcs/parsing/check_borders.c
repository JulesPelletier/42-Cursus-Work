/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:03:59 by Jules             #+#    #+#             */
/*   Updated: 2021/08/16 16:03:08 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    check_params(t_all *all)
{
    int i;
    int j;

    i = 0;
    while (i < all->params.len_x)
    {
        j = 0;
        while (j < all->params.len_y)
        {
            if (all->map.map[i][j] == 'C')
                all->params.count_collect++;
            if (all->map.map[i][j] == 'P')
                all->params.count_starting_pos++;
            if (all->map.map[i][j] == 'E')
                all->params.count_exit++;
            j++;
        }
        i++;
    }
}

void    check_rectangular(t_all *all)
{
    int i;
    int check;
    
    i = 0;
    check = all->params.len_y;
    while (all->map.map[i] && i < all->params.len_x - 1)
    {
        if ((int)ft_strlen(all->map.map[i]) != check)
            all->params.flag_rectangular = -1;
        i++;
    }
}

void    check_border(t_all *all)
{
    int i;
    int j;

    i = 0;
    while (i < all->params.len_x)
    {
        j = 0;
        while (j < all->params.len_y)
        {
            if ((i == 0 || i == all->params.len_x - 1) && all->map.map[i][j] != '1')
                all->params.flag_map_closed = -1;
            if ((j == 0 || j == all->params.len_y - 1) && all->map.map[i][j] != '1')
                all->params.flag_map_closed = -1;
            j++;
        }
        i++;
    }
}

int redir_error(t_all *all)
{
    if (all->params.count_collect < 1)
    {
        errors_part1(10);
        return (-1);
    }
    if (all->params.count_exit < 1)
    {
        errors_part1(11);
        return (-1);
    }
    if (all->params.count_starting_pos != 1)
    {
        errors_part1(8);
        return (-1);
    }
    return (0);
}

int     final_param_check(t_all *all)
{
    check_border(all);
    check_rectangular(all);
    check_params(all);
    if (all->params.flag_map_closed < 0)
    {
        errors_part1(6);
        return (-1);
    }
    if (all->params.flag_rectangular < 0)
    {
        errors_part1(7);
        return (-1);
    }
    if (redir_error(all) == -1)
        return (-1);
    return (1);
}