/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:15:03 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 14:20:01 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		length_lst;

	length_lst = 0;
	if (!(lst))
		return (0);
	else
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			length_lst++;
		}
		return (length_lst + 1);
	}
}
