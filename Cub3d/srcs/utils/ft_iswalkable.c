/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswalkable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:47:27 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:47:10 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswalkable(int i)
{
	if (i == '0' || i == 'N' || i == 'E' || i == 'S' || i == 'W')
		return (1);
	return (0);
}
