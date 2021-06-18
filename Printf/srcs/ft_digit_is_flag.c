/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_is_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:35 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:37:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_digitflags(const char *str, int pos, t_flags *flags)
{
	flags->width = ft_atoi(&str[pos]);
	while (ft_isdigit(str[pos]))
		pos++;
	return (pos);
}
