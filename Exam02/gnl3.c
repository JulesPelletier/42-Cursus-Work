/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:32:46 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/21 14:10:55 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

#define BUFFER_SIZE 1

char    *ft_free(char *s)
{
    free(s);
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
    int     i;
    char    *new;

    i = 0;
    if (!s)
        s = "";
    if (ft_strlen(s) < start)
        len = 0;
    new = malloc(sizeof(char) * len + 1);
    if (!new)
        return (NULL);
    while (i < len && s[start + i])
    {
        new[i] = s[start + i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *new;

    i = 0;
    j = 0;
    if (!s1)
        s1 = ft_substr("", 0, 0);
    new = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
    {
        ft_free(s1);
        return (NULL);
    }
    while (s1[i])
        new[j++] = s1[i++];
    i = 0;
    while (s2[i])
        new[j++] = s2[i++];
    new[j] = '\0';
    s1 = ft_free(s1);
    return (new);
}

int ft_s_is(char *s, char c)
{
    int i;

    i = 0;
    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

void    ft_parse(char **keep, char *buffer, int *ret, int fd)
{
    while (ft_s_is(*keep, '\n') == -1 && (*ret = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[*ret] = '\0';
        *keep = ft_strjoin(*keep, buffer);
    }
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]) && (i + 1 < n))
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)s2[i]);
}

char    *get_next_line(int fd)
{
    char     *keep = NULL;
    char            buffer[BUFFER_SIZE + 1];
    int             ret;
    char            *tmp;
    char            *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    ft_parse(&keep, buffer, &ret, fd);
    if (ft_s_is(keep, '\n' > -1))
    {
        line = ft_substr(keep, 0, ft_s_is(keep, '\n'));
        tmp = ft_substr(keep, 0, ft_strlen(keep));
        keep = ft_free(keep);
        keep = ft_substr(tmp, (ft_s_is(tmp, '\n') + 1), ft_strlen(tmp));
        tmp = ft_free(tmp);

        return (line);
    }
    else
    {
        line = ft_substr(keep, 0, ft_strlen(keep));
        keep = ft_free(keep);
        return (line);
    }
    return (NULL);
}

int main(void)
{
    int     fd;
    int     count;
    char    *line;
    
    fd = open("gnl3.c", O_RDONLY);
    count = 0;
    while ((line = get_next_line(fd)) != NULL && count < 180)
    {
        printf("line %d : %s\n", count, line);
        count++;
    }
    return (0);
}