/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:12 by thzeribi          #+#    #+#             */
/*   Updated: 2020/04/19 03:53:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*print_c(t_tab *tab)
{
	char c;
	c = (char)va_arg(tab->args, int);
	if ((int)c >= 0)
	{
		if (tab->combin[1] == '0' && tab->combin[0] != '-')
			display(tab, '0', tab->width - 1, 1);
		else if (tab->combin[0] != '-')
			display(tab, ' ', tab->width - 1, 1);
		if (tab->precisions == -1)
			display(tab, ' ', 1, 0);
		else
			display_c(tab, c);
	}
	if (tab->arg_flag == '%')
		ft_putchar('%');
	if (tab->combin[0] == '-')
		display(tab, ' ', tab->width - 1, 1);
	return (tab);
}

t_tab	*print_s(t_tab *tab)
{
	char		*str;
	int			len;

	len = 0;
	str = va_arg(tab->args, char *);
	if (tab->precisions && str)
		str = ft_strndup(str, tab->precisions);
	else if (!tab->precisions && str)
		str = ft_strdup(str);
	else if (tab->precisions && !str)
		str = ft_strndup("(null)", tab->precisions);
	else if (!tab->precisions && !str)
		str = ft_strdup("(null)");
	if (str)
		len = ft_strlen(str);
	tab->len += len;
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
		display(tab, '0', tab->width - len, 1);
	else if (tab->combin[0] != '-')
		display(tab, ' ', tab->width - len, 1);
	if (tab->precisions == -1)
		display(tab, ' ', len, 0);
	else
		ft_putstr(str);
	if (tab->combin[0] == '-')
		display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}

t_tab			*print_d(t_tab *tab)
{
	intmax_t	nbr;
	int				width;
	int				indent;

	nbr = (int)(va_arg(tab->args, int));
	if (nbr == 0 && tab->precisions == 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	if (nbr < 0)
	{
		tab->combin[0] = '-';
		nbr *= -1;
	}
	indent = (tab->combin[0] == '-') ? 1 : 0;
	width = get_width(nbr);
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
	{
		tab->precisions = tab->width;
		if (nbr < 0 || tab->combin[0])
			tab->precisions--;
	}
	display_d(tab, nbr, width, indent);
	return (tab);
}