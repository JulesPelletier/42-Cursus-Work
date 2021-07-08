/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:25:30 by Jules             #+#    #+#             */
/*   Updated: 2021/07/08 09:30:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_doublons(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.len)
	{
		j = i + 1;
		while (j < stack.len)
		{
			if (stack.stack[i] == stack.stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
