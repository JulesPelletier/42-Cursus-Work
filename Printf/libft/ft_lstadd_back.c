/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:36:13 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 14:14:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	if (*alst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}
