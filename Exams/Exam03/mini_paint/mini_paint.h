/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:46:34 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/08 07:04:31 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

typedef struct	s_params
{
	int		width;
	int		height;
	char	background;
}				t_params;

typedef struct	s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	c;
}				t_circle;

typedef struct	s_all
{
	t_params	params;
	t_circle	circle;
	char		**map;
	FILE		*file;
}				t_all;

#endif