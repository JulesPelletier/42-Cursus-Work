/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:35:34 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 10:57:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_add_error(t_all *all, int error)
{
	all->err.errors[all->err.nb_errors] = error;
	all->err.nb_errors++;
}

void	ft_show_errors(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->err.nb_errors)
	{
		printf("Error %d : %d \n", i, all->err.errors[i]);
		i++;
	}
}
