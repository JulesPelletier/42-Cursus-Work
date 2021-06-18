/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:41:13 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:43:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void		ft_putunbr(unsigned int n, t_flags *flags)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = 4294967295 + n + 1;
	else
		nbr = n;
	if (n / 10)
		ft_putnbr(nbr / 10, flags);
	ft_putchar(((nbr % 10) + 48), flags);
}
