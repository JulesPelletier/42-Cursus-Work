/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:39:27 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 15:21:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	add_error(t_all *all, t_list **error, char *str)
{
	t_list	*new_error;

	all->error += 1;
	new_error = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(error, new_error);
}

void	show_error(t_list *error)
{
	char	*line;

	line = NULL;
	ft_putstr("Error\n");
	while (error)
	{
		line = ft_strdup(error->content);
		ft_putstr(line);
		free(line);
		error = error->next;
	}
}
