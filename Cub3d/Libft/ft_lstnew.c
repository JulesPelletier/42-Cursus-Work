/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:18:42 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 12:47:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list1;

	list1 = (t_list *)malloc(sizeof(t_list));
	if (list1 == NULL)
		return (NULL);
	list1->content = content;
	list1->next = NULL;
	return (list1);
}
