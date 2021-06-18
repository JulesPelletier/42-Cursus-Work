/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:28:27 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/18 17:49:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		itoa_func(int nbr)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nbr);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

void	ft_dot(int nbr, t_flags *flags)
{
	int		lenbis;
	int		tmp;

	tmp = flags->precision;
	lenbis = itoa_func(nbr);
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		lenbis = 0;
	if (nbr < 0)
		flags->len++;
	if (flags->precision < lenbis)
		flags->len--;
	if (nbr > 0 && flags->precision < lenbis)
		flags->len++;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	if (nbr < 0)
	{
		ft_putchar('-', flags);
		lenbis--;
	}
	while (flags->precision-- > lenbis)
		ft_putchar('0', flags);
	flags->precision = tmp;
}

void	flags_id(int nbr, t_flags *flags)
{
	if (flags->dash > 0 || flags->dot > 0)
		flags->zero = 0;
	if (nbr < 0 && flags->dot == 0)
		ft_putchar('-', flags);
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot(nbr, flags);
	if (!(flags->dot > 0 && flags->precision <= 0 && nbr == 0))
		ft_putnbr(nbr, flags);
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

int		ft_display_id(int nbr, int pos, t_flags *flags)
{
	flags->len = itoa_func(nbr);
	flags->len = (flags->len > flags->precision) ? flags->len
		: flags->precision;
	if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_id(nbr, flags);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (nbr < 0)
			ft_putchar('-', flags);
		if (flags->dot > 0 && flags->precision == 0 && nbr == 0)
			return (pos + 1);
		ft_putnbr(nbr, flags);
	}
	return (pos + 1);
}
