/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:38:26 by julpelle          #+#    #+#             */
/*   Updated: 2021/08/13 14:18:50 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	int		count2;
	char	*ptr;

	count = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (!(ptr))
		return (NULL);
	count2 = 0;
	while (s1[count2] != '\0')
	{
		ptr[count2] = s1[count2];
		count2++;
	}
	ptr[count2] = '\0';
	return (ptr);
}
