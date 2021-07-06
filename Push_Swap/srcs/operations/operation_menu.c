/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:37:31 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 15:49:26 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_operation_move(t_all *all)
{
    if (ft_strncmp(all->op.line, "sa", 2) == 0)
        ft_sa_move(all);
    if (ft_strncmp(all->op.line, "sb", 3) == 0) 
        ft_sb_move(all);
    if (ft_strncmp(all->op.line, "ss", 3) == 0) 
        ft_ss_move(all);
    if (ft_strncmp(all->op.line, "pa", 3) == 0) 
        ft_pa_move(all);
    if (ft_strncmp(all->op.line, "pb", 3) == 0) 
        ft_pb_move(all);
    if (ft_strncmp(all->op.line, "ra", 3) == 0) 
        ft_ra_move(all);
    if (ft_strncmp(all->op.line, "rb", 3) == 0) 
        ft_rb_move(all);
    if (ft_strncmp(all->op.line, "rr", 3) == 0) 
        ft_rr_move(all);
    if (ft_strncmp(all->op.line, "rra", 4) == 0) 
        ft_rra_move(all);
    if (ft_strncmp(all->op.line, "rrb", 4) == 0) 
        ft_rrb_move(all);    
    if (ft_strncmp(all->op.line, "rrr", 4) == 0) 
        ft_rrr_move(all);
}

void    ft_operation_options(t_all *all)
{
    if (ft_strncmp(all->op.line, "-v", 3) == 0) 
        ft_show_2stacks_char(all->stA, all->stB);
}

void    ft_operation_apply(t_all *all)
{
    ft_operation_move(all);
    ft_operation_options(all);
}