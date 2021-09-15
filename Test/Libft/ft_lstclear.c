/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:38 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:55:50 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**temp;

	if ((*lst) != 0 && del)
	{
		while ((*lst) != 0)
		{
			temp = lst;
			(*del)((*lst)->content);
			free(*lst);
			*lst = (*temp)->next;
		}
	}
	else
		return ;
}
