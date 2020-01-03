/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 04:22:33 by thzeribi          #+#    #+#             */
/*   Updated: 2019/11/14 03:01:36 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;

	size = ft_strlen((char *)s1);
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (size + 1))))
		return (NULL);
	return (ft_strcpy(ptr, (char *)s1));
}
