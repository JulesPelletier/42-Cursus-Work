/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:56:49 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 15:28:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

#define BUFFER_SIZE 10

int	gnl_error(char *tmp, char *st_str)
{
	if (tmp)
		free(tmp);
	if (st_str)
		free(st_str);
	return (-1);
}

int	gnl_setstrs(char (*buff)[], char **tmp, char **st_str, char ***line)
{
	int	i;
	int	j;

	if (ft_strchr(*buff, '\n'))
	{
		*st_str = ft_strdup(ft_strchr(*buff, '\n') + 1);
		if (!(*st_str))
			return (-1);
	}
	*st_str = ft_strdup(*buff);
	else if (!(*st_str))
		return (-1);
	i = 0;
	while ((*tmp)[i] && (*tmp)[i] != '\n')
		i++;
	**line = malloc(sizeof(char) * (i + 1));
	if (!(**line))
		return (-1);
	j = 0;
	while (j < i)
		(**line)[j++] = (*tmp)[j++];
	(**line)[j] = '\0';
	free(*tmp);
	return (0);
}

int	gnl_loop(char (*buff)[], char **tmp, int *ret, int fd)
{
	char	*tmp2;

	while (!ft_strchr(*buff, '\n') && *ret)
	{
		*ret = read(fd, *buff, BUFFER_SIZE);
		if ((*ret == -1))
			return (-1);
		(*buff)[*ret] = '\0';
		tmp2 = ft_strjoin(*tmp, *buff);
		if (!(tmp2))
			return (-1);
		free(*tmp);
		*tmp = tmp2;
	}
	return (0);
}

int	gnl_tmpinit(char (*buff)[], char **tmp, char **st_str, int fd)
{
	int		ret;

	if (!*st_str)
	{
		ret = read(fd, *buff, BUFFER_SIZE);
		if ((ret == -1))
			return (-1);
		(*buff)[ret] = '\0';
		tmp = ft_strdup(*buff);
		if (!(*tmp))
			return (-1);
	}
	else
	{
		ret = 1;
		if (!ft_strcpy(*buff, *st_str))
			return (-1);
		*tmp = ft_strdup(*buff);
		if (!(*tmp))
			return (-1);
		free(*st_str);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE < 1 ? 1 : BUFFER_SIZE + 1];
	char		*tmp;
	static char	*st_str = NULL;

	tmp = NULL;
	if (fd == -1 || !line || BUFFER_SIZE < 1)
		return (gnl_error(tmp, st_str));
	ret = gnl_tmpinit(&buff, &tmp, &st_str, fd);
	if ((ret == -1))
		return (gnl_error(tmp, st_str));
	if (gnl_loop(&buff, &tmp, &ret, fd) == -1)
		return (gnl_error(tmp, st_str));
	if (gnl_setstrs(&buff, &tmp, &st_str, &line) == -1)
		return (gnl_error(tmp, st_str));
	if (ret < BUFFER_SIZE && !ft_strchr(buff, '\n'))
	{
		free(st_str);
		st_str = NULL;
		return (0);
	}
	return (1);
}
