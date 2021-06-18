/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:30:12 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/18 15:40:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void	ft_dot_s(char *str, t_flags *flags)
{
	int		idx;

	idx = 0;
	if (flags->dash == 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
	while (str[idx] && flags->precision > 0)
	{
		ft_putchar(str[idx], flags);
		idx++;
		flags->precision--;
	}
}

void	flags_s(char *str, t_flags *flags)
{
	if (flags->dash > 0)
		flags->zero = 0;
	if (flags->zero > 0)
		while (flags->width-- > flags->len)
			ft_putchar('0', flags);
	if (flags->dot > 0)
		ft_dot_s(str, flags);
	else
	{
		if (flags->dot > 0 && flags->precision == 0)
			return ;
		else
			ft_putstr(str, flags);
	}
	if (flags->dash > 0)
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
}

char	*null_func(char *str)
{
	char	*tmp;

	if (!(tmp = ft_strdup("(null)")))
		return (NULL);
	str = tmp;
	free(tmp);
	return (str);
}

int		ft_display_s(char *str, int pos, t_flags *flags)
{
	if (str == NULL)
		str = null_func(str);
	flags->len = ft_strlen(str);
	if (flags->precision > 0)
		flags->len = (flags->len > flags->precision) ? flags->precision
			: flags->len;
	if (flags->dot > 0 && flags->precision == 0)
		flags->len = 0;
	if (flags->flag > 0)
		flags_s(str, flags);
	else
	{
		while (flags->width-- > flags->len)
			ft_putchar(' ', flags);
		if (flags->dot > 0 && flags->precision == 0)
			return (pos + 1);
		else
			ft_putstr(str, flags);
	}
	return (pos + 1);
}
