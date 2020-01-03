/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 02:03:32 by thzeribi          #+#    #+#             */
/*   Updated: 2019/11/15 00:15:22 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	size_t	sign;
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? 1 : 0;
	if (!(res = (char *)malloc(sizeof(char) * (ft_nbrlen(n) + 1))))
		return (NULL);
	while (n != 0)
	{
		res[i++] = (sign) ? (-1 * (n % 10)) + 48 : (n % 10) + 48;
		n /= 10;
	}
	if (sign)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}
