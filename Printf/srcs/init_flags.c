/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:57 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 15:43:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->flag = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->ret = 0;
	flags->len = 0;
}
