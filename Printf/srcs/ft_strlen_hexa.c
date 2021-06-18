/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:53 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:42:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_strlen_basehexa(unsigned long int n, char *base, t_flags *flags,
			int len)
{
	if (n >= 16)
		len = ft_strlen_basehexa(n / 16, base, flags, len);
	len++;
	return (len);
}
