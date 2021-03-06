/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:09:06 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:32:32 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_keys(t_st *st)
{
	st->keys.w = 0;
	st->keys.a = 0;
	st->keys.s = 0;
	st->keys.d = 0;
	st->keys.up = 0;
	st->keys.down = 0;
	st->keys.left = 0;
	st->keys.right = 0;
	st->keys.plus = 0;
	st->keys.keepplus = 0;
	st->keys.minus = 0;
	st->keys.keepminus = 0;
	st->keys.esc = 0;
}
