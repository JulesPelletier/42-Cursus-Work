/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:46:50 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:25:51 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*optirr(t_push_swap *all, char *str, char *str2)
{
	if (all->count_rb == 0 && str[1] == 'a')
	{
		all->count_ra += 1;
		return (str);
	}
	if (all->count_rb >= 1 && str[1] == 'a')
	{
		ft_clear("rb", str2, 2);
		all->count_rb--;
		return ("rr");
	}
	if (all->count_ra == 0 && str[1] == 'b')
	{
		all->count_rb += 1;
		return (str);
	}
	if (all->count_ra >= 1 && str[1] == 'b')
	{
		ft_clear("ra", str2, 2);
		all->count_ra--;
		return ("rr");
	}
	return (str);
}

char	*optirrr(t_push_swap *all, char *str, char *str2)
{
	if (all->count_rrb == 0 && str[2] == 'a')
	{
		all->count_rra += 1;
		return (str);
	}
	if (all->count_rrb >= 1 && str[2] == 'a')
	{
		ft_clear("rrb", str2, 3);
		all->count_rrb--;
		return ("rrr");
	}
	if (all->count_rra == 0 && str[2] == 'b')
	{
		all->count_rrb += 1;
		return (str);
	}
	if (all->count_rra >= 1 && str[2] == 'b')
	{
		ft_clear("rra", str2, 3);
		all->count_rra--;
		return ("rrr");
	}
	return (str);
}

char	*gestrr(t_push_swap *all, char *str, char *str2)
{
	if (str[0] == 'r')
	{
		if (str[1] == 'r')
			return (optirrr(all, str, str2));
		else
			return (optirr(all, str, str2));
	}
	all->count_ra = 0;
	all->count_rra = 0;
	all->count_rb = 0;
	all->count_rrb = 0;
	return (str);
}
