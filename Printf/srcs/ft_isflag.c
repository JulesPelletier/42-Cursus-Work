/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:39 by julpelle          #+#    #+#             */
/*   Updated: 2020/01/21 13:44:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

int		ft_is_flag(const char *str, int pos)
{
	if (str[pos] == '-' || str[pos] == '0' || str[pos] == '.'
		|| str[pos] == '*')
		return (0);
	else
		return (1);
}
