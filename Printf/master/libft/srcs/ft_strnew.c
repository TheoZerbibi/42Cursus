/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:56:22 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/28 17:59:50 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *str;

	if (!(str = (char *)malloc((len - 1) * sizeof(*str))))
		return (NULL);
	ft_bzero(str, len + 1);
	return (str);
}
