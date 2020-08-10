/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:12 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/10 01:55:01 by thzeribi         ###   ########.fr       */
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
		else if (tab->width_is_neg == 0)
			display(tab, ' ', tab->width - 1, 1);
		if (tab->width_is_neg == -1)
			display(tab, ' ', 1, 0);
		else
			display_c(tab, c);
	}
	if (tab->arg_flag == '%')
		ft_putchar('%');
	if (tab->width_is_neg == 1)
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
	else if (tab->width_is_neg == 0)
		display(tab, ' ', tab->width - len, 1);
	if (tab->precisions == -1)
		display(tab, ' ', len, 0);
	else
		ft_putstr(str);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}

t_tab			*print_d(t_tab *tab)
{
	long int	nbr;
	int				width;
	int				indent;

	nbr = (int)(va_arg(tab->args, int));
	if (nbr == 0 && tab->precisions < 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	if (tab->precisions < 0)
		tab->prec_neg = 1;
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

t_tab		*print_x(t_tab *tab)
{
	long int	nbr;
	int				indent;
	int				len;
	int				blank;

	nbr = (int)(va_arg(tab->args, int));
	indent = (tab->combin[0] == '-') ? 1 : 0;

	len = ft_nbrlen(nbr);
	blank = len;
	if (len <= tab->precisions && tab->precisions >= 0)
		blank = tab->precisions;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (tab->width_is_neg == 0)
		display(tab, ' ', tab->width - len, 0);
	if (tab->prec_neg == 0)
		display(tab, '0', tab->precisions - len, 0);
	ft_putlnbr_base(nbr, BASE);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
	return (tab);
}