/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:42:53 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:49:15 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	create_map(t_input *args)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	while (args->line[i] && ((args->line)[i] == ' ' || (args->line)[i] == '1'))
	{
		if (args->line[i] == '1')
		{
			size = ft_strlen(args->line);
			dup = malloc(sizeof(char) * (size + 3));
			if (!dup)
				return ;
			i = -1;
			while (++i < size)
				dup[i] = args->line[i];
			dup[i] = 'x';
			i++;
			dup[i] = '\0';
			args->map = ft_strjoin_bis(args->map, dup);
			ft_free(dup);
			break ;
		}
		i++;
	}
}
