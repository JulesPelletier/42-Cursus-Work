/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:46 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:31:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_dispatch_conversion(const char *str, int pos,
			va_list params, t_flags *flags)
{
	pos += 1;
	while (!(ft_is_converter(str, pos)))
		pos = search_flags(params, str, pos, flags);
	if (str[pos] == '%')
		return (ft_display_perc(pos, flags));
	if (str[pos] == 'c')
		return (ft_display_c(va_arg(params, int), pos, flags));
	if (str[pos] == 'd' || str[pos] == 'i')
		return (ft_display_id(va_arg(params, int), pos, flags));
	if (str[pos] == 'u')
		return (ft_display_u(va_arg(params, int), pos, flags));
	if (str[pos] == 's')
		return (ft_display_s(va_arg(params, char *), pos, flags));
	if (str[pos] == 'p')
		return (ft_p((unsigned long int)(va_arg(params, void *)), pos, flags));
	if (str[pos] == 'x')
		return (ft_x((unsigned long int)(va_arg(params, void *)), pos, flags));
	if (str[pos] == 'X')
		return (ft_cx((unsigned long int)(va_arg(params, void *)), pos, flags));
	return (-1);
}
