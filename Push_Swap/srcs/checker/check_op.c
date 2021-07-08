/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:33:25 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 10:02:17 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_swap(t_all *all)
{
	if (ft_strncmp(all->op.line, "sa", 3) != 0
		&& ft_strncmp(all->op.line, "sb", 3) != 0
		&& ft_strncmp(all->op.line, "ss", 3) != 0)
		return (0);
	else
		return (1);
}

int	ft_check_push(t_all *all)
{
	if (ft_strncmp(all->op.line, "pa", 3) != 0
		&& ft_strncmp(all->op.line, "pb", 3) != 0)
		return (0);
	else
		return (1);
}

int	ft_check_rotate(t_all *all)
{
	if (ft_strncmp(all->op.line, "ra", 3) != 0
		&& ft_strncmp(all->op.line, "rb", 3) != 0
		&& ft_strncmp(all->op.line, "rr", 3) != 0
		&& ft_strncmp(all->op.line, "rra", 4) != 0
		&& ft_strncmp(all->op.line, "rrb", 4) != 0
		&& ft_strncmp(all->op.line, "rrr", 4) != 0)
		return (0);
	else
		return (1);
}

int	ft_check_options(t_all *all)
{
	if (ft_strncmp(all->op.line, "-v", 3) != 0
		&& ft_strncmp(all->op.line, "color", 6) != 0)
		return (0);
	else
		return (1);
}

int	ft_check_operations(t_all *all)
{
	if (ft_check_swap(all) == 1
		|| ft_check_push(all) == 1
		|| ft_check_rotate(all) == 1
		|| ft_check_options(all) == 1)
		return (1);
	else
		return (0);
}
