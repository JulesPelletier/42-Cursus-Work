/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:22 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:11:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	end_str(t_push_swap *all, char *tmp, int i, int j)
{
	tmp[i + j++] = '\n';
	tmp[i + j] = '\0';
	free(all->str);
	all->str = tmp;
}

void	function_add(t_push_swap *all)
{
	if (all->stA.first <= all->stA.min)
	{
		all->stA.fsort = 1;
		update_output(all, "ra");
		return (new_min(all, 0));
	}
}
