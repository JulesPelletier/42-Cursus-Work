/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:53 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/18 14:33:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		va;
	int			idx;
	t_flags		flags;

	ft_init_flags(&flags);
	va_start(va, str);
	while (params)
	{
		idx = 0;
		while (str[idx])
		{
			if (str[idx] == '%')
				idx = ft_dispatch_conversion(str, idx, va, &flags);
			while (str[idx] && str[idx] != '%')
			{
				ft_putchar(str[idx], &flags);
				idx++;
			}
		}
	}
	va_end(va);
	return (flags.ret);
}
