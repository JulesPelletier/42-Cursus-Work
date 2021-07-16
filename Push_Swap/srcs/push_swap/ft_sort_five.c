/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:21:59 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/09 13:30:44 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_check_pos(t_all *all)
{
    while (all->stB.len != 0)
    {
        if (all->stB.stack[0] < all->stA.stack[0])
        {
            ft_pa_move(all);
            ft_putstr("pa\n");
        }
        else if (all->stB.stack[0] < all->stA.stack[1])
        {
            ft_ra_move(all);
            ft_pa_move(all);
            ft_rra_move(all);
            ft_putstr("ra\npa\nrra\n");
        }
        else if (all->stB.stack[0] < all->stA.stack[2])
        {
            ft_rra_move(all)
            ft_pa_move(all);
            ft_ra_move(all);
            ft_putstr("rra\npa\nra\n");
        }
    }
}

void    ft_sort_five(t_all *all)
{
    ft_pb_move(all);
    ft_pb_move(all);
    ft_putstr("pb\npb\n");
    ft_options_three(all, all->stA);
    ft_check_pos(all);
}