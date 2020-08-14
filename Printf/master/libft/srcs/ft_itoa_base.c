/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:26:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/14 02:43:14 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int a, int b)
{
	if (b == 0)
		return (1);
	return (a * (ft_pow(a, b - 1)));
}


static int	ft_nbrlen_itoa(int nbr, int base)
{
	int len;

	len = 1;
	while (ft_pow(base, len) < nbr)
		len++;
	return (len);
}

char		*ft_itoa_base(int nbr, int base)
{
	char		*str;
	size_t	len;
	int			neg;

	neg = 0;
	if (nbr < 0)
	{
		if (base == 10)
			neg = 1;
		nbr *= -1;
	}
	len = ft_nbrlen_itoa(nbr, base);
	if (!(str = ft_strnew(len + neg)))
		return (NULL);
	while (len-- > 0)
	{
		*(str + len + neg) = (nbr % base) + ((nbr % base > 9 )? 'A' - 10 : '0');
		nbr /= base;
	}
	if (neg)
		*str = '-';
	return (str);
}
