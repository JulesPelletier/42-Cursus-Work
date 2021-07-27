/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:31:59 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:57:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_boucle(long int count, int fd)
{
	char	c;

	if ((count / 10) > 0)
		ft_boucle(count / 10, fd);
	c = (count % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	count;

	count = n;
	if (count == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (count < 0)
	{
		write(fd, "-", 1);
		count = -count;
	}
	ft_boucle(count, fd);
}
