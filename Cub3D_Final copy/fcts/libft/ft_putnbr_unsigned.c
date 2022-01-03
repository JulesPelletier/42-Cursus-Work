#include "libft.h"
#include <stdio.h>

void	ft_putnbr_unsigned(long long int nb)
{
	unsigned long long int u1;

	u1 = 0;
	if (nb < 0)
	{
		u1 = 4294967295 + nb + 1;
		ft_putnbr(u1);
	}
	else
	{
		ft_putnbr(nb);
	}
}

