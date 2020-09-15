/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:10:40 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/08 00:44:53 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long int nbr)
{
	size_t	size;

	size = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
