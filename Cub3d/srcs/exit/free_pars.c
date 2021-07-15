/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:13:37 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:26:47 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free_pars(t_st *st)
{
	if (st->pars.line != NULL)
		free(st->pars.line);
	if (st->pars.strmap != NULL)
		free(st->pars.strmap);
}
