/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:52:51 by julpelle          #+#    #+#             */
/*   Updated: 2019/08/13 08:50:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[i] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	affichage(long nbr, char *base)
{
	int		taille;
	long	resultat;

	taille = ft_strlen(base);
	resultat = 0;
	if (nbr >= taille)
	{
		affichage(nbr / taille, base);
		ft_putchar(base[nbr % taille]);
	}
	else
		ft_putchar(base[nbr % taille]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long nombre;

	nombre = nbr;
	if (check_base(base) == 1)
	{
		if (nombre < 0)
		{
			ft_putchar('-');
			nombre = -nombre;
		}
		affichage(nombre, base);
	}
}
