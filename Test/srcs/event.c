/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:34:50 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	event(t_all *all)
{
	check_collectibles(all);
	if (all->exit == 0)
		draw(all);
	else
	{
		if (all->gps.event == 1)
			new_map(all);
		all->gps.event = 0;
	}
	return (0);
}