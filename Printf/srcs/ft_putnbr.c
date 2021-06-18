/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:36:54 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/18 15:38:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void		ft_putnbr(int n, t_flags *flags)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	if (n / 10)
		ft_putnbr(nbr / 10, flags);
	ft_putchar(((nbr % 10) + 48), flags);
}
