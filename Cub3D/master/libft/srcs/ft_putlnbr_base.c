/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:49:04 by thzeribi          #+#    #+#             */
/*   Updated: 2021/01/01 13:11:20 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Print is a Boolean
** print = 1 (True), function return size + write
** print = 0 (False), function only return size
*/

int	ft_putlnbr_base(unsigned long int nbr, char *base, int upper, int print)
{
	int				i;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr < base_len)
	{
		if (print == 1)
		{
			if (upper == 1)
				ft_putchar(ft_toupper(base[nbr]));
			else
				ft_putchar(base[nbr]);
		}
		return (1);
	}
	else
	{
		i += ft_putlnbr_base(nbr / base_len, base, upper, print);
		i += ft_putlnbr_base(nbr % base_len, base, upper, print);
	}
	return (i);
}
