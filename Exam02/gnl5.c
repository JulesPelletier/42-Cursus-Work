/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:42:01 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/25 23:25:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	while(s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*push_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*cut_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*keep;
	int			ret;
	char		*line;
	int			flag;

	ret = 1;
	flag = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (flag == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
			flag = 1;
		else
		{
			buffer[ret] = '\0';
			keep = ft_strjoin(keep, buffer);
		}
	}
	line = push_line(keep);
	keep = cut_line(keep);
	return (line);
}

int main(void)
{
	int		fd;
	char	*line;
	int		count;

	line = NULL;
	fd = open("gnl5.c", O_RDONLY);
	//printf("FD : %d\n", fd);
	line = get_next_line(fd);
	//printf("Check Before\n");
	//printf("Line : %s\n", line);
	count = 1;
	while (line)
	{
		//printf("Check in Boucle\n");
		printf("Line %d : %s\n", count, line);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	printf("%s", line);
	free(line);
}