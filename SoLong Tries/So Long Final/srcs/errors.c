/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:52:56 by Jules             #+#    #+#             */
/*   Updated: 2021/09/20 16:51:02 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	add_error(t_all *all, t_list **error, char *error_msg)
{
	t_list	*new_error;

	all->error += 1;
	new_error = ft_lstnew(ft_strdup(error_msg));
	ft_lstadd_back(error, new_error);
}

void	show_errors(t_list *error)
{
	char	*msg;
	
	msg = NULL;
	ft_putstr_fd("Error : \n", 1);
	while (error)
	{
		msg = ft_strdup(error->content);
		ft_putstr_fd(msg, 1);
		free(msg);
		error = error->next;
	}
}