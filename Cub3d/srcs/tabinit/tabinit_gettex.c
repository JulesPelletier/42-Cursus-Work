/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_gettex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:58:13 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:42:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_gettex_datainit(t_st *st, int j)
{
	void	**tex_ptr;
	int		*tex_bpp;
	int		*tex_sl;
	int		*tex_end;
	int		i;

	tex_ptr = st->tex.tex_ptr[j];
	tex_bpp = st->tex.tex_bpp[j];
	tex_sl = st->tex.tex_sl[j];
	tex_end = st->tex.tex_end[j];
	i = 0;
	while (i < 4)
	{
		(st->tex.tex_data[j][i]) = (int *)mlx_get_data_addr(tex_ptr[i],
				&tex_bpp[i], &tex_sl[i], &tex_end[i]);
		if (st->tex.tex_data[j][i] == NULL)
			ft_error(st, -21);
		i++;
	}
}

void	ft_tabinit_gettex_ptrinit(t_st *st, int j)
{
	void	**tex_ptr;
	char	**pathtex;
	int		*tex_w;
	int		*tex_h;
	int		i;

	tex_ptr = st->tex.tex_ptr[j];
	pathtex = st->tex.pathtex[j];
	tex_w = st->tex.tex_w[j];
	tex_h = st->tex.tex_h[j];
	i = 0;
	while (i < 4)
	{
		tex_ptr[i] = mlx_xpm_file_to_image(st->mlx.mlx_ptr,
				pathtex[i], &tex_w[i], &tex_h[i]);
		if (tex_ptr[i] == NULL)
			ft_error(st, -21);
		i++;
	}
}

void	ft_tabinit_gettex(t_st *st)
{
	if (ft_wallisvalid(st, '1') == 1)
	{
		ft_tabinit_gettex_ptrinit(st, 0);
		ft_tabinit_gettex_datainit(st, 0);
	}
}
