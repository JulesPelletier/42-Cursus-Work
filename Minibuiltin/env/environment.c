/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:24:28 by Jules             #+#    #+#             */
/*   Updated: 2021/10/14 15:33:45 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_jules.h"

t_list	**ft_envp(char *envp[], char *content, t_list *env)
{
	static t_list	*environment = NULL;

	if (envp != NULL)
		environment = ft_tab_to_lst(envp);
	else if (content != NULL)
		ft_lst_pushback(&environment, content);
	else if (env != NULL)
		environment = env;
	return (&environment);
}