/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:53:41 by thzeribi          #+#    #+#             */
/*   Updated: 2019/11/06 09:33:49 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < 65 || c > 90)
	{
		if (c < 97 || c > 122)
		{
			if (c < 48 || c > 57)
				return (0);
			return (3);
		}
		return (2);
	}
	return (1);
}
