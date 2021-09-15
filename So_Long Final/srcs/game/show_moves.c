/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:26:17 by Jules             #+#    #+#             */
/*   Updated: 2021/09/13 17:26:40 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	show_moves(t_all *all)
{
	ft_putstr_fd("Moves : ", 1);
    ft_putnbr_fd(all->moves, 1);
    ft_putstr_fd("\n", 1);
}