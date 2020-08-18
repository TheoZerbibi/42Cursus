/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:49:04 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/18 22:15:17 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnbr_base(unsigned long int nbr, const char *base, int upper)
{
	int				i;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr < base_len)
	{
		if (upper == 1)
			ft_putchar(ft_toupper(base[nbr]));
		else
			ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putlnbr_base(nbr / base_len, base, upper);
		i += ft_putlnbr_base(nbr % base_len, base, upper);
	}
	return (i);
}
