/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:48:35 by Jules             #+#    #+#             */
/*   Updated: 2021/07/15 14:25:32 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void    test_parsing(t_st *st)
{
    printf("Parsing Line : %s\n", st->pars.line);
    printf("Parsing Resol : %d\n", st->pars.parsedresol);
    printf("Parsing Floor : %d\n", st->pars.parsedfloor);
    printf("Parsing Ceiling : %d\n", st->pars.parsedceiling);
    printf("Parsing ret : %d\n", st->pars.retgnl);
    printf("Parsing floor R : %d\n", st->pars.fr);
    printf("Parsing floor G : %d\n", st->pars.fg);
    printf("Parsing floor B : %d\n", st->pars.fb);
    printf("Parsing ceiling R : %d\n", st->pars.cr);
    printf("Parsing ceiling G : %d\n", st->pars.cg);
    printf("Parsing ceiling B : %d\n", st->pars.cb);
    printf("Parsing Tested \n\n\n");
}

void    test_maps(t_st *st)
{
    printf("Map number : %d\n", st->maps.nbrmaps);
    printf("Map sizex : %d\n", st->maps.sizemapx);
    printf("Map sizey : %d\n", st->maps.sizemapy);
    printf("Map startset : %d\n", st->maps.startset);
    printf("Map Tested\n\n\n");
}

void    test_speed(t_st *st)
{
    printf("Movement Speed : %f\n", st->spd.movespeed);
    printf("Rotation Speed : %f\n", st->spd.rotspeed);
}