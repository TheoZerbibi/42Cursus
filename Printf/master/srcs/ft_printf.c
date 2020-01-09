/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:19 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/09 01:15:04 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_flags(char **str, va_list op)
{
	(void)op;
	printf("%s\n", *str);
	return (0);
}

int					ft_printf(const char *str, ...)
{
	va_list op;

	va_start(op, str);
	while (*str != '\0')
	{
		if (*str == '%')
			ft_flags((char **)&str, op);
		else
			ft_putchar(*str);
		str++;
	}
	va_end(op);
	return (0);
}
