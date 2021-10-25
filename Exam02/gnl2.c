/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:22:56 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/21 12:33:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 1

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    int     size;
    int     i;
    int     j;

    if (!s1 && !s2)
        return (NULL);
    i = 0;
    j = 0;
    size = ft_strlen(s1) + ft_strlen(s2);
    res = (char *)malloc(sizeof(char) * (size + 1));
    if (!res)
        return (NULL);
    if (s1)
    {
        while (s1[i])
        {
            res[i] = s1[i];
            i++;
        }
    }
    while (s2[j])
    {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}


char    *get_next_line(int fd)
{
    char        buffer[BUFFER_SIZE + 1]
    static char *line;
    int         ret;

    ret = 1;
    line = NULL;
    if (fd < 0)
        return (NULL);
    while (buffer[0] != '\n' && ret != 0)
    {
        if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
            return (NULL);
        buffer[ret] = '\0';
        line = ft_strjoin(line, buffer);
    }
    
}