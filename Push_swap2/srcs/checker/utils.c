/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:05:27 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:11:11 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	*listeur(int *list, int len, char *line, char **action)
{
	int		*list2;
	int		y;
	int		i;

	list2 = malloc(sizeof(int) * (len + 2));
	if (!(list))
		ft_stop5();
	i = 0;
	while (i < len)
	{
		list2[i] = list[i];
		i++;
	}
	y = 0;
	while (action[y])
	{
		if (!ft_strncmp(line, action[y], ft_strlen(line)))
			break ;
		y++;
	}
	list2[i] = y;
	list2[++i] = 0;
	free(list);
	return (list2);
}

void	freeaction(char **action, char *line, int *list)
{
	int		i;

	i = 0;
	while (i < 11)
		free(action[i++]);
	free(action);
	free(list);
	free(line);
}

void	applications(int *list, t_checker *all, char **action, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_lecteur(action[list[i]], all);
		optionv(all, action, list, i);
		i++;
	}
	if (check_sorted(all) > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_ch(t_checker *all, int len, char **action)
{
	char		*line;
	int			*list;
	int			i;

	list = malloc(sizeof(int) * 2);
	if (!(list))
		ft_stop4("3", all);
	i = 0;
	while (get_next_line(all->fd, &line))
	{
		if (!check_op(line, action))
		{
			freeaction(action, line, list);
			ft_stop4("3", all);
		}
		i++;
		list = listeur(list, len, line, action);
		len++;
		free(line);
	}
	applications(list, all, action, len);
	freeaction(action, line, list);
}