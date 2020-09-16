/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:47:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/14 22:52:26 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(long int nbr)
{
	int width;

	width = 1;
	while ((nbr /= 10) > 0)
		width++;
	return (width);
}

t_tab	*print_d(t_tab *tab)
{
	long int	nbr;
	int			indent;

	nbr = (int)(va_arg(tab->args, int));
	if (nbr == 0 && tab->precisions < 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	if (nbr == 0 && tab->width <= 0 && tab->precisions <= 0
		&& tab->combin[3] == '.')
		return (tab);
	if (tab->precisions < 0)
		tab->prec_neg = 1;
	if (nbr < 0)
	{
		tab->combin[0] = '-';
		nbr *= -1;
		tab->nbr_is_neg = 1;
	}
	indent = (tab->combin[0] == '-') ? 1 : 0;
	display_d(tab, nbr, get_width(nbr), indent);
	return (tab);
}

void	print_positive(t_tab *tab, long int nbr, int width)
{
	int		blank;

	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	if ((blank = width) && width <= tab->precisions
		&& tab->precisions >= 0 && tab->param == 0)
		blank = tab->precisions;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (nbr == 0 && tab->precisions == 0 && tab->combin[3] == '.'
		&& tab->combin[1] != '0')
	{
		if (tab->width > 0)
			display(tab, ' ', tab->width, FALSE);
		else
			tab->len -= 1;
		return ;
	}
	d_utils_positive(tab, width, blank);
	d_utils_positive_print(tab, nbr, width, blank);
}

void	print_minus(t_tab *tab, long int nbr, int width, int is_neg)
{
	int			blank;
	char		neg_char;
	int			already_neg;

	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	neg_char = (is_neg) ? '-' : '\0';
	blank = width;
	already_neg = 0;
	if (width <= tab->precisions && tab->precisions >= 0)
		blank = tab->precisions;
	if (neg_char)
		blank++;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (nbr == 0 && tab->precisions == 0 && tab->combin[3] == '.')
	{
		tab->len -= 1;
		if (tab->width > 0)
			display(tab, ' ', tab->width, FALSE);
		else
			tab->len -= 1;
		return ;
	}
	d_utils_minus(tab, blank, neg_char, already_neg);
	d_utils_minus_print(tab, nbr, width, blank);
}