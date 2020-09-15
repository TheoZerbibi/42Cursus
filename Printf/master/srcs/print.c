/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:12 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/15 20:16:10 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*print_c(t_tab *tab)
{
	char c;
	if (tab->arg_flag == '%')
		c = '%';
	else
		c = (char)va_arg(tab->args, int);
	if ((int)c >= 0 || tab->arg_flag == '%')
	{
		if (tab->combin[1] == '0' && tab->combin[0] != '-')
			display(tab, '0', tab->width - 1, 1);
		else if (tab->width_is_neg == 0 && tab->combin[0] != '-')
			display(tab, ' ', tab->width - 1, 1);
		if (tab->width_is_neg == -1)
			display(tab, ' ', 1, 0);
		else
		{
			tab->len += 1;
			ft_putchar(c);
		}
	}
	if (tab->width_is_neg == 1 || tab->combin[0] == '-')
		display(tab, ' ', tab->width - 1, 1);
	return (tab);
}

t_tab		*print_s(t_tab *tab)
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
	if (tab->width == 0 && tab->precisions == 0 && tab->combin[3] == '.')
	{
		free(str);
		return (tab);
	}
	display_s(tab, str);
	return (tab);
}

t_tab		*print_x(t_tab *tab, int upper)
{
	long int	nbr;
	int			indent;
	int			len;
	int			blank;

	nbr = (unsigned)(va_arg(tab->args, unsigned int));
	if ((int)nbr < 0)
		tab->combin[0] = '-';
	indent = (tab->combin[0] == '-') ? 1 : 0;
	len = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	blank = (len <= tab->precisions && tab->precisions > 0 && tab->width > 0) ?
	tab->precisions : len;
	if (tab->width_is_neg == 1 && tab->combin[1] == '0'
		&& tab->combin[0] == '-')
		tab->len += tab->width;
	else if (tab->width_is_neg == 1 && (tab->combin[0] == '-' ||
		tab->param == 0) && (tab->param == -1 || tab->combin[1] == '0'))
		tab->len += blank;
	else if (blank <= tab->width || tab->width_is_neg == 1)
		tab->len += tab->width;
	else
		tab->len += blank;
	display_x(tab, nbr, blank, upper);
	return (tab);
}

t_tab		*print_p(t_tab *tab)
{
	char		*str;
	long int	nbr;
	int			indent;

	indent = 0;
	nbr = (unsigned long)(va_arg(tab->args, unsigned long int));
	indent = (tab->combin[0] == '-') ? 1 : 0;
	if (tab->combin[0] == '-' || tab->width_is_neg == 1)
		indent = 1;
	else
		indent = 0;
	if (!(str = ft_itoa_base(nbr, 16, 'a')))
		exit(ERROR);
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
	{
		tab->precisions = tab->width;
		tab->width = 0;
	}
	display_p(tab, str, indent);
	return (tab);
}

t_tab		*print_u(t_tab *tab)
{
	long int	nbr;
	int			indent;
	int			len;

	indent = 0;
	nbr = (unsigned long)(va_arg(tab->args, unsigned int));
	if (nbr == 0 && tab->precisions < 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	len = get_width(nbr);
	if (tab->precisions < 0)
		tab->prec_neg = 1;
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
		tab->precisions = tab->width;
	display_d(tab, nbr, get_width(nbr), 0);
	return (tab);
}
