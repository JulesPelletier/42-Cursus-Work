/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:54 by Jules             #+#    #+#             */
/*   Updated: 2021/08/13 14:47:38 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    errors_part1(int error)
{
    ft_putstr(RED"ERROR \n"RESET);
    if (error == 1)
        ft_putstr("Missing map file\n");
    if (error == 2)
        ft_putstr("Too many arguments : only 1 map required\n");
    if (error == 3)
        ft_putstr("Invalid extesion : must be '.ber'\n");
    if (error == 4)
        ft_putstr("Invalid character in map, only ('0','1','C','E','P') \n");
    if (error == 5)
        ft_putstr("Unable to read file\n");
    if (error == 6)
        ft_putstr("Map not closed\n");
    if (error == 7)
        ft_putstr("Map not rectangular\n");
    if (error == 8)
        ft_putstr("More than one starting position\n");
    if (error == 9)
        ft_putstr("Input is a directory, not a file\n");
    if (error == 10)
        ft_putstr("0 collectibles present in map (at least 1 needed)\n");
    if (error == 11)
        ft_putstr("0 exits present in map (at least 1 needed)\n");
    exit(1);
}