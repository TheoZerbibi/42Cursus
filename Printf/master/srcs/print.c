/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:12 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/02 22:04:11 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*print_c(t_tab *tab)
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

t_tab		*print_d(t_tab *tab)
{
	long int	nbr;
	int			indent;

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
	display_d(tab, nbr, get_width(nbr), indent);
	return (tab);
}

/*
** Soucis sur le calcul de tab->len
*/

t_tab		*display_x(t_tab *tab, long int nbr, char *str, int indent)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && nbr &&
			tab->combin[1] == '0' && tab->width)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && nbr)
	{
		tab->width -= 2;
		tab->len += 2;
	}
	n_b = (n_w <= tab->precisions && tab->precisions > 0) ? tab->precisions : n_w;
	tab->len += (n_b <= tab->width) ? tab->width : n_b;
	if (!indent)
		display(tab, ' ', tab->width - n_b, 0);
	display(tab, '0', tab->precisions - n_w, 0);
	ft_putstr(str);
	if (indent)
		display(tab, ' ', tab->width - n_b, 0);
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

//	printf(" len : %d | prec : %ld | ", len, tab->precisions);

	blank = (len <= tab->precisions && tab->precisions > 0) ? tab->precisions : len;

//	printf("blank : %d | width : %ld | tablen bef : %ld | ", blank, tab->width, tab->len);
//	printf("%d - %d | ", tab->width_is_neg, tab->prec_neg);

	tab->len += (blank <= tab->width || tab->width_is_neg == 1) ? tab->width : blank;

//	printf("tablen af : %ld", tab->len);

	if (tab->width_is_neg == 0)
		display(tab, ' ', tab->width - blank, FALSE);
	if (tab->param == 0 && tab->combin[0] != '-')
		display(tab, '0', tab->precisions - len, FALSE);
	else
		blank = len;
	ft_putlnbr_base(nbr, BASE, upper, TRUE);
	if (tab->width_is_neg == 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, FALSE);
	else if (tab->width_is_neg == 1 && tab->combin[0] == '-')
		display(tab, ' ', tab->width - (blank + len + 2), FALSE);
	return (tab);
}

t_tab		*print_x_old(t_tab *tab, int upper)
{
	long int	nbr;
	int			indent;
	int			len;
	int			blank;

	nbr = (unsigned)(va_arg(tab->args, unsigned int));
	if ((int)nbr < 0)
		tab->combin[0] = '-';
	indent = (tab->combin[0] == '-') ? 1 : 0;
	len = ft_nbrlen(nbr);
	blank = len;

	if (len <= tab->precisions && tab->precisions >= 0)
		blank = tab->precisions;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (tab->width_is_neg == 0)
		display(tab, ' ', tab->width - blank, FALSE);
	if (tab->param == 0 && tab->combin[0] != '-')
		display(tab, '0', tab->precisions - len, FALSE);
	else
		blank = len;
	ft_putlnbr_base(nbr, BASE, upper, TRUE);
	if (tab->width_is_neg == 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, FALSE);
	else if (tab->width_is_neg == 1 && tab->combin[0] == '-')
		display(tab, ' ', tab->width - (blank + len + 2), FALSE);
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
	if (tab->precisions == 0 && nbr == 0)
		*str = '\0';
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
	nbr = (unsigned long)(va_arg(tab->args, unsigned long int));
	if (nbr == 0 && tab->precisions < 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	len = get_width(nbr);
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
		tab->precisions = tab->width;
	display_u(tab, nbr, get_width(nbr));
	return (tab);
}
