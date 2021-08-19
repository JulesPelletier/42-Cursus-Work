/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:10:33 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:04:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int check_args(int ac, char **av)
{
    if (ac == 1)
    {
        errors_part1(1);
        return (-1);
    }
    if (ac > 2)
    {
        errors_part1(2);
        return (-1);
    }
    if (ac == 2)
    {
        if (check_extension(av[1]) == -1)
            return (-1);
    }
    return (1);
}