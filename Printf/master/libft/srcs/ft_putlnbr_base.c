/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:49:04 by thzeribi          #+#    #+#             */
/*   Updated: 2020/06/10 14:53:42 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putlnbr_base(unsigned long int nbr, const char *base)
{
	int						i;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr < base_len)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		i += ft_putlnbr_base(nbr / base_len, base);
		i += ft_putlnbr_base(nbr % base_len, base);
	}
	return (i);
}