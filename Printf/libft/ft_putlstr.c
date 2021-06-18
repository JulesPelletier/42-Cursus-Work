/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:44:28 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:47:29 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlstr(char *str, int len, t_flags *flags)
{
	while (*str && len > 0)
	{
		ft_putchar(*str, flags);
		len--;
		str++;
	}
}
