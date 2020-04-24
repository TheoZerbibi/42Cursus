/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:56:22 by thzeribi          #+#    #+#             */
/*   Updated: 2020/04/24 17:09:51 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(str, '\0', len + 1);
	return (str);
}
