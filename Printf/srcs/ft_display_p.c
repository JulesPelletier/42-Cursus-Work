/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:28:58 by julpelle          #+#    #+#             */
/*   Updated: 2020/01/21 15:03:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void		ft_dot_p(int nbr, t_flags *flags, char *base)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = 0;
	lenbis = ft_strlen_basehexa(nbr, base, flags, lenbis);
	if (nbr < 0)
		flags->len += 1;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	while (flags->precision-- > lenbis)
		ft_putchar('0', flags);
	flags->precision = tmp;
}

void		flags_p(unsigned long int nbr, t_flags *flags, char *base)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->dot == 0)
		ft_putstr("0x", flags);
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_p(nbr, flags, base);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putnbr_basehexa(nbr, base, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

int			ft_p(unsigned long int n, int pos, t_flags *flags)
{
	char				base[17];
	int					len;

	len = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	flags->len = ft_strlen_basehexa(n, base, flags, len);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && n == 0)
		flags->len = 0;
	flags->len += 2;
	if (flags->flag > 0)
		flags_p(n, flags, base);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		if (flags->dot > 0 && flags->precision == 0 && n == 0)
			return (pos + 1);
		ft_putnbr_basehexa(n, base, flags);
	}
	return (pos + 1);
}
