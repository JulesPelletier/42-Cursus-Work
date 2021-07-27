/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:05:02 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:01:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_stop5(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_stop4(char *str, t_checker *all)
{
	if (all->flag[6])
		freechar(all->av_dup);
	free(all->str);
	if (str[0] == '1')
		ft_stop5();
	free(all->stA.st);
	if (str[0] == '2')
		ft_stop5();
	free(all->stB.st);
	ft_stop5();
}
