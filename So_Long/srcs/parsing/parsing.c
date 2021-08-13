/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:20:48 by Jules             #+#    #+#             */
/*   Updated: 2021/08/12 12:24:26 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int parsing(t_all *all, int ac, char **av)
{
    if (check_args(ac, av) == -1)
        return (-1);
    create_map(all);
    if (check_map_char(all) != 1)
        return (-1);
    if (final_param_check(all) < 0)
        return (-1);
    printf(GREEN"\nMap valid\n"RESET);
    return (1);
}