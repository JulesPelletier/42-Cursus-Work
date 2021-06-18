/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:33:07 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:42:30 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_dashzero(const char *str, int pos, t_flags *flags, int nbr)
{
	if (str[pos - 1] == '0' || str[pos - 1] == '-')
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			flags->dash = 1;
			flags->zero = 0;
		}
		flags->width = nbr;
	}
	if (str[pos - 1] == '.')
	{
		if (nbr < 0)
			flags->dot = 0;
		flags->precision = nbr;
	}
	return (nbr);
}

int		ft_precision(const char *str, int pos, t_flags *flags)
{
	pos += 1;
	if (ft_isdigit(str[pos]) == 1)
	{
		flags->precision = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]) == 1)
			pos++;
	}
	return (pos);
}

int		ft_star(va_list va, const char *str, int pos, t_flags *flags)
{
	int		nbr;

	nbr = va_arg(va, int);
	if (str[pos - 1] == '0' || str[pos - 1] == '-' || str[pos - 1] == '.')
		nbr = ft_dashzero(str, pos, flags, nbr);
	else
	{
		if (nbr < 0)
		{
			flags->dash = 1;
			flags->flag = 1;
			nbr = -nbr;
		}
		flags->width = nbr;
	}
	return (pos + 1);
}

int		ft_width(const char *str, int pos, t_flags *flags)
{
	pos += 1;
	if (ft_isdigit(str[pos]) == 1)
	{
		flags->width = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]) == 1)
			pos++;
	}
	return (pos);
}

int		search_flags(va_list va, const char *str, int pos, t_flags *flags)
{
	if (ft_isdigit(str[pos]) && str[pos] != '0')
		pos = ft_digitflags(str, pos, flags);
	if (!(ft_is_flag(str, pos)))
	{
		if (str[pos] == '0' || str[pos] == '-' || str[pos] == '.')
			flags->flag = 1;
		if (str[pos] == '0')
			flags->zero = 1;
		if (str[pos] == '-')
			flags->dash = 1;
		if (str[pos] == '0' || str[pos] == '-')
			pos = ft_width(str, pos, flags);
		if (str[pos] == '.')
		{
			flags->dot = 1;
			pos = ft_precision(str, pos, flags);
		}
		if (str[pos] == '*')
		{
			flags->star = 1;
			pos = ft_star(va, str, pos, flags);
		}
	}
	return (pos);
}
