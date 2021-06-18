/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:16:30 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 14:16:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *lst_tmp1;
	t_list *lst_tmp2;

	lst_tmp1 = *lst;
	lst_tmp2 = NULL;
	(*del)(lst_tmp1->content);
	while (lst_tmp1->next != NULL)
	{
		(*del)(lst_tmp1->content);
		lst_tmp1 = lst_tmp1->next;
	}
	free(lst_tmp1);
	*lst = lst_tmp2;
}
