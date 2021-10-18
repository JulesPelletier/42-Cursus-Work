/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:38:41 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 15:54:38 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_line(char *line, t_list **error, t_all *all)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!is_in_str(line[i], "01CEP"))
		{
			add_error(all, error, "Invalid character in the map\n");
			return (0);
		}	
	}
	return (1);
}

int	is_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

void	get_map(char *line, t_list **list)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
}

char	*add_spaces(char *str, int max)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char *) * max + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < max)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}
