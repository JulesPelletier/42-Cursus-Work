/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_getsprt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:59 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:40:42 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_getsprt_datainit(t_st *st, int i)
{
	void	**sprt_ptr;
	int		*sprt_bpp;
	int		*sprt_sl;
	int		*sprt_end;

	sprt_ptr = st->sprt.sprt_ptr;
	sprt_bpp = st->sprt.sprt_bpp;
	sprt_sl = st->sprt.sprt_sl;
	sprt_end = st->sprt.sprt_end;
	st->sprt.sprt_data[i] = (int *)mlx_get_data_addr(sprt_ptr[i],
			&sprt_bpp[i], &sprt_sl[i], &sprt_end[i]);
	if (st->sprt.sprt_data[i] == NULL)
		ft_error(st, -21);
	i++;
}

void	ft_tabinit_getsprt_ptrinit(t_st *st, int i)
{
	void	**sprt_ptr;
	char	**pathsprt;
	int		*sprt_w;
	int		*sprt_h;

	sprt_ptr = st->sprt.sprt_ptr;
	pathsprt = st->sprt.pathsprt;
	sprt_w = st->sprt.sprt_w;
	sprt_h = st->sprt.sprt_h;
	sprt_ptr[i] = mlx_xpm_file_to_image(st->mlx.mlx_ptr,
			pathsprt[i], &sprt_w[i], &sprt_h[i]);
	if (sprt_ptr[i] == NULL)
		ft_error(st, -21);
	i++;
}

void	ft_tabinit_getsprt(t_st *st)
{
	if (ft_spriteisvalid(st, '2') == 1)
	{
		ft_tabinit_getsprt_ptrinit(st, 0);
		ft_tabinit_getsprt_datainit(st, 0);
	}
}
