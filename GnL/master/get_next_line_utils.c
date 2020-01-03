/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:14:14 by thzeribi          #+#    #+#             */
/*   Updated: 2019/12/11 22:23:58 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew_gnl(size_t size)
{
	char	*str;
	char	*temp;
	size_t	len;

	len = size + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	temp = str;
	while (len-- > 0)
		*temp++ = (unsigned char)'\0';
	return (str);
}

char	*ft_strcpy_gnl(char *dest, const char *src)
{
	int i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	int		size;
	char	n;

	n = '\0';
	if (!s1)
		s1 = &n;
	if (!s2)
		s2 = &n;
	size = ft_multi_func(s1, 0) + ft_multi_func(s2, 0);
	if (!(new = ft_strnew_gnl(size)))
		return (NULL);
	if (!ft_strcpy_gnl(new, s1))
	{
		free(new);
		return (NULL);
	}
	if (!ft_strcpy_gnl(new + ft_multi_func(s1, 0), s2))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strnew_gnl(len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

char	*ft_strdup_gnl(const char *src)
{
	int		size;
	char	*dest;

	if (!src)
		return (NULL);
	size = ft_multi_func(src, 0);
	if (!(dest = (char *)malloc(sizeof(*src) * (size + 1))))
		return (NULL);
	ft_strcpy_gnl(dest, src);
	return (dest);
}
