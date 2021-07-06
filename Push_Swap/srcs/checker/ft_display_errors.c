/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:07:36 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 10:03:20 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_display_error(int error)
{
    if (error == 1)
        ft_putstr("ERROR : wrong input arguments (only ints)\n");
    if (error == 2)
        ft_putstr("ERROR : wrong command\n");
    if (error == 3)
        ft_putstr("ERROR : Stack A doesn't have enough values");
    if (error == 4)
        ft_putstr("ERROR : Stack B doesn't have enough values");
        
}

void    ft_display_errors(t_all *all)
{
    int     i;

    i = 0;
    while (i < all->err.nb_errors)
    {
        ft_display_error(all->err.errors[i]);
        i++;
    }
}