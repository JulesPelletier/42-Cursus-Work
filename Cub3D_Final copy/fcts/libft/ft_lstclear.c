/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:16:30 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/10 15:06:31 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursive_clear(t_list *ptr, void (*del)(void*))
{
	if (ptr->next)
		recursive_clear(ptr->next, del);
	del(ptr->content);
	free(ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !*lst)
		return ;
	recursive_clear(*lst, del);
	*lst = 0;
}
