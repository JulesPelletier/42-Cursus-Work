/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:01 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/18 17:31:02 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void	flags_c(char c, t_flags *flags)
{
	if (flags->dash > 0)
		flags->zero = 0;
	if (flags->zero > 0)
	{
		if (flags->star == 0)
			while (flags->width-- > 1)
				ft_putchar('0', flags);
		else
			flags->dash = 1;
	}
	else if (flags->zero == 0 && flags->dash == 0)
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
	ft_putchar(c, flags);
	if (flags->dash > 0)
	{
		flags->zero = 0;
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
	}
}

int		ft_display_c(int c, int pos, t_flags *flags)
{
	if (flags->flag > 0)
		flags_c(c, flags);
	else
	{
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
		ft_putchar(c, flags);
	}
	return (pos + 1);
}
