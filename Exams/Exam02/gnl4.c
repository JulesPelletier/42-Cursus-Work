/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:15:13 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/22 13:48:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

char    *ft_free(char *s)
{
    free(s)
    s = NULL;
    return (s);
}

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

char    *ft_substr(char *s, int start, int len)
{
    char    *res;
    int     i;

    i = 0;
    if (!s)
        return (NULL);
    if (ft_strlen(s) < start)
        return (NULL);
    res = (char *)malloc(sizeof(char) * len + 1)
    if (!res)
        return (NULL);
    while (i < len && s[start + i])
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';
    retrun (res);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    int     size;
    int     i;
    int     j;

    if (!s1)
        s1 = ft_substr("", 0, 0);
    i = 0;
    j = 0;
    size = ft_strlen(s1) + ft_strlen(s2);
    res = malloc(sizeof(char) * (size + 1));
    if (!res)
    {
        ft_free(s1);
        return (NULL);
    }
    while(s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    s1 = ft_free(s1);
    return (res);   
}

int ft_s_is(char *str, char c)
{
    int i;

    i = 0;
    if (!s)
        return (-1);
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

void    ft_parse(char **keep, char *buffer, int *ret, int fd)
{
    while (ft_s_is(keep, '\n') == -1 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[*ret] = '\0';
        *keep = ft_strjoin(*keep, buffer);
    }
}

char    *get_next_line(int fd)