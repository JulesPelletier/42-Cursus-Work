/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:07:53 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 14:42:50 by Jules            ###   ########.fr       */
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
    while (all.err.kill == 0 && get_next_line(0, &all.op.line) > 0)
    {
        if (ft_check_operations(&all) != 1)
            return (0);
        else
            ft_operation_apply(&all);
        if (ft_check_sort(&all) == 1)
        {
            all.err.kill = 1;
            ft_putstr("OK\n");
        }
    }
    return (0);
}