/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:24:59 by Jules             #+#    #+#             */
/*   Updated: 2021/08/16 16:12:49 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int check_file_or_dir(char *str)
{
    DIR *dir;
    
    dir = opendir(str);
    if (errno == ENOTDIR)
        return (1);
    else
        return (-1);
    closedir(dir);
}

void    get_map_size(char *str, t_all *all)
{
    int     fd;
    char    *line;
    int     len_x;
    int     len_y;

    line = NULL;
    len_x = 0;
    len_y = 0;
    fd = open(str, O_RDONLY);
    if (fd < 0)
        errors_part1(5);
    if (check_file_or_dir(str) == -1)
        errors_part1(9);
    while (get_next_line(fd, &line) >= 0 && ft_isdigit(line[0]) == 1)
    {
        len_x++;
        if ((int)ft_strlen(line) > len_y)
            len_y = ft_strlen(line);
    }
    if (ft_isdigit(line[0]))
        len_x++;
    all->params.len_x = len_x;
    all->params.len_y = len_y;
    close(fd);
}

void    create_map(t_all *all)
{
    int     i;
    char    *line;
    char    *content;
    int     fd;

    //get_map_size(all->map.filename, all);
    //map = (char **)malloc(sizeof(char *) * (all->params.len_x + 1));
    fd = open(all->map.filename, O_RDONLY);
    i = 0;
    content = NULL;
    while (get_next_line(fd, &line))
    {
        //printf("I : %d | Line : %s \n", i, line);
        if (ft_isdigit(line[0]) != 1)
            break;
        if (ft_isdigit(line[0]) == 1)
        {
            content = ft_strjoin(content, line);
            all->params.len_x++;
            if ((int)ft_strlen(line) > all->params.len_y)
                all->params.len_y = ft_strlen(line);
            i++;
        }
        content = ft_strjoin(content, "\n");
    }
    if (ft_isdigit(line[0]) == 1)
    {
        content = ft_strjoin(content, line);
        content = ft_strjoin(content, "\n");
        all->params.len_x++;
    }
    all->map.map = ft_split(content, '\n');
    close(fd);
}

/*
void    create_map(t_all *all)
{
    int     i;
    char    **map;
    char    *line;
    int     fd;

    //get_map_size(all->map.filename, all);
    //map = (char **)malloc(sizeof(char *) * (all->params.len_x + 1));
    fd = open(all->map.filename, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) && i < all->params.len_x - 1)
    {
        //printf("I : %d | Line : %s \n", i, line);
        if (ft_isdigit(line[0]) == 1)
        {
            map[i] = ft_strdup(line);
            i++;
        }
    }
    map[i] = ft_strdup(line);
    map[i + 1] = NULL;
    all->map.map = map;
    show_map(all);
    close(fd);
}
*/
