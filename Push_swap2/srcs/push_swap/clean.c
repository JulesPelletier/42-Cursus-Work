/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:42:26 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 18:18:30 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**malloqueur(char **argv)
{
	int		count;
	int		count2;
	int		count3;
	char	**argv2;

	count = 0;
	count3 = 0;
	while (argv[count])
	{
		count2 = 0;
		while (argv[count][count2])
		{
			if (argv[count][count2] == ' ')
				count3++;
			count2++;
		}
		count++;
		count3++;
	}
	count3++;
	argv2 = malloc(sizeof(char *) * count3);
	if (!argv2)
		exit (1);
	argv2[count3 - 1] = NULL;
	return (argv2);
}

char	**replace(char **argv, t_push_swap *all)
{
	int		count;
	int		count2;
	int		count4;
	char	**argv3;
	char	**argv2;

	all->count = 0;
	count2 = 0;
	argv2 = malloqueur(argv);
	count = 0;
	while (argv[count])
	{
		argv3 = ft_split(argv[count], ' ');
		count4 = 0;
		while (argv3[count4])
		{
			argv2[count2] = argv3[count4];
			count2++;
			count4++;
		}
		free(argv3);
		count++;
	}
	return (argv2);
}

char	**ft_show(char **str, t_push_swap *all)
{
	int	count;

	count = 0;
	all->flag[4] = 1;
	while (str[count])
		count++;
	all->ac_dup = count;
	return (str);
}

char	**all_char(int argc, char **argv, t_push_swap *all)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	all->flag[4] = 0;
	while (argv[count])
	{
		count2 = 0;
		while (argv[count][count2])
		{
			if (argv[count][count2] == ' ')
			{
				return (ft_show(replace(argv, all), all));
			}
			count2++;
		}
		count++;
	}
	all->ac_dup = argc;
	return (argv);
}
