/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/03/11 03:00:12 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display(t_tab *tab, int c, int len, int update_len)
{
	char *str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = ft_strnew(len)))
			exit(ERROR);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

void	display_c(t_tab *tab, wint_t c)
{
	if (c <= 127)
	{
		tab->len += 1;
		ft_putchar(c);
	}
}
