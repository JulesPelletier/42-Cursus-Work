/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:30:29 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/18 15:40:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		itoa_func_u(unsigned int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot_u(unsigned int nbr, t_flags *flags)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = itoa_func_u(nbr);
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

void	flags_u(unsigned int nbr, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_u(nbr, flags);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putunbr(nbr, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

int		ft_display_u(int nbr, int pos, t_flags *flags)
{
	unsigned int		n;

	if (nbr < 0)
		n = 4294967295 + nbr + 1;
	else
		n = nbr;
	flags->len = itoa_func_u(n);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_u(n, flags);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
			return (pos + 1);
		else
			ft_putunbr(n, flags);
	}
	return (pos + 1);
}
