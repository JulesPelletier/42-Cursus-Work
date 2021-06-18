/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:27:55 by julpelle          #+#    #+#             */
/*   Updated: 2020/01/21 15:03:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void			ft_dot_cx(unsigned long int nbr, t_flags *flags, char *base
				, int len)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = len;
	lenbis = ft_strlen_basehexa(nbr, base, flags, lenbis);
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		lenbis = 0;
	if (nbr < 0)
		flags->len += 1;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	if (nbr >= 0)
		while (flags->precision-- > lenbis)
			ft_putchar('0', flags);
	flags->precision = tmp;
}

void			flags_cx(unsigned long int nbr, t_flags *flags, char *base
				, int len)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_cx(nbr, flags, base, len);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putnbr_basehexa(nbr, base, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

unsigned int	unsigned_func(int n)
{
	unsigned int nb;

	if (n < 0)
		nb = 4294967295 + n + 1;
	else
		nb = n;
	return (nb);
}

int				ft_cx(int n, int pos, t_flags *flags)
{
	char				base[17];
	int					len;
	unsigned int		nb;

	len = 0;
	nb = unsigned_func(n);
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	flags->len = ft_strlen_basehexa(nb, base, flags, len);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && n == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_cx(nb, flags, base, len);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0 && n == 0)
			return (pos + 1);
		else
			ft_putnbr_basehexa(nb, base, flags);
	}
	return (pos + 1);
}
