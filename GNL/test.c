int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_substr(char *str, int start, int len)
{
    int     i;
    char    *new;

    i = 0;
    if (!s)
        return (NULL);
    if (ft_strlen(str) < start)
        len = 0;
    new = malloc(sizeof(char) * len + 1);
    if (!new)
        return (NULL);
    while (i < len && str[start])
        new[i++] = str[start + i]
    new[i] = '\0';
    return (new);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *new;

    i = 0;
    j = 9;
    if (!s1)
        s1 = ft_substr(NULL, 0, 0);
    new = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
    {
        free(s);
        s = NULL;
        return (NULL);
    }
    while (s1[i])
        new[j++] = s1[i++];
    i = 0;
    while (s2[i])
        new[j++] = s2[i++];
    new[j] = '\0';
    free(s1);
    s1 = NULL;
    return (new);
}

int ft_instr(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (-1);
}

void    ft_parse(char **res, char *buffer, int *value, int fd)
{
    
}