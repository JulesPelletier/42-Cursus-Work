/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:28:43 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:38:31 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void		ft_putnbr_basehexa(unsigned long int n, char *base, t_flags *flags)
{
	char			c;

	if (n >= 16)
		ft_putnbr_basehexa(n / 16, base, flags);
	c = base[n % 16];
	ft_putchar(c, flags);
}
