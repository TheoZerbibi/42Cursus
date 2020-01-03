/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:35:06 by thzeribi          #+#    #+#             */
/*   Updated: 2019/11/12 15:48:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst >= dstsize)
		return (lensrc + dstsize);
	ft_strncat(dst, src, dstsize - lendst - 1);
	return (lendst + lensrc);
}
