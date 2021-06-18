/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:38:54 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:38:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void	ft_putstr(char *str, t_flags *flags)
{
	int		pos;

	pos = 0;
	while (str[pos])
	{
		write(1, &str[pos], 1);
		flags->ret++;
		pos++;
	}
}
