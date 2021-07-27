/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:04:54 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:05:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error2(char *str)
{
	if (str[0] == 'e')
		return ;
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error(char *str, t_push_swap *all)
{
	if (all->flag[4])
		freechar(all->av_dup);
	free(all->str);
	if (str[0] == '1')
		ft_error2("malloc");
	free(all->stA.st);
	if (str[0] == '2')
		ft_error2("malloc");
	free(all->stB.st);
	ft_error2("malloc");
}
