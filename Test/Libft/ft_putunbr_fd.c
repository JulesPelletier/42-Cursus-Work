/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:40 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:57:38 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char			num;

	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	num = n % 10 + 48;
	ft_putchar_fd(num, fd);
}
