/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:27:48 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 16:50:17 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     main(int ac, char **av)
{
    t_all   all;
    
    ft_init_all(&all);
    if (ac < 2)
        return (0);
    ft_fill_stack(&all, ac, av);
    if (all.err.kill == 1 || ft_check_doublons(all.stA) == 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    ft_get_median(&all.stA);
    ft_get_max(&all.stA);
    ft_get_min(&all.stA);
    ft_get_divider(&all.stA);
    ft_algo(&all);
    if (all.err.kill == 1)
        ft_putstr("OK\n");
    return (0);
}