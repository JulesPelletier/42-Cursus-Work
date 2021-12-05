/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:12:50 by julpelle          #+#    #+#             */
/*   Updated: 2021/11/22 11:20:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_exit(char *str, int fd)
{
	ft_putstr_fd("Error : ", fd);
	ft_putstr_fd(str, fd);
	return (-1);
}