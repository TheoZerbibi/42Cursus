/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:12 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/31 06:48:51 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*print_c(t_tab *tab)
{
	char c;

	c = (char)va_arg(tab->args, int);
	ft_putchar(c);
	return (tab);
}

t_tab	*print_s(t_tab *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (str)
	{
		if (tab->precisions == -1)
			str = strdup(str);
		else if (tab->precisions > -1)
			str = strndup(str, tab->precisions);
	}
	else if (!str)
	{
		if (tab->precisions == -1)
			str = strdup("(null)");
		else if (tab->precisions > -1)
			str = strndup("(null)", tab->precisions);
	}
	len = ft_strlen(str);
	tab->len += len;
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
		display(tab, '0', tab->width- len, 1);
	else if (tab->combin[0] != '-')
		display(tab, ' ', tab->width - len, 1);
	ft_putstr(str);
	if (tab->combin[0] == '-')
		display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}
