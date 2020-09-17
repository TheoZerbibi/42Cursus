/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:02:09 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/17 05:54:49 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"


static void	print_positive(t_tab *tab, long int nbr, int width)
{
	int		blank;
	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	if ((blank = width) && width <= tab->precisions
		&& tab->precisions >= 0 && tab->prec_is_neg == 0)
		blank = tab->precisions;
	if (nbr == 0 && tab->precisions == 0 && tab->combin[3] == '.'
		&& tab->combin[1] != '0' && tab->combin[0] != '-')
	{
		if (tab->width > 0)
			display(tab, ' ', tab->width, TRUE);
		else
			tab->len -= 1;
		return ;
	}
	d_utils_positive_print(tab, nbr, width, blank);
}

static void	print_minus(t_tab *tab, long int nbr, int width, int is_neg)
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
	d_utils_minus(tab, blank, neg_char, already_neg);
	d_utils_minus_print(tab, nbr, width, blank);
}

static t_tab		*display_d(t_tab *tab, long int nbr, int width, int is_neg)
{
	if (is_neg)
		print_minus(tab, nbr, width, is_neg);
	else
		print_positive(tab, nbr, width);
	return (tab);
}

t_tab	*print_d(t_tab *tab)
{
	long int	nbr;
	int			indent;

	nbr = (int)(va_arg(tab->args, int));
	if (nbr == 0 && tab->precisions == 1 && tab->prec_null == 1)
	{
		display(tab, ' ', tab->width, TRUE);
		return (tab);
	}
	if (nbr == 0 && tab->width <= 0 && tab->precisions <= 0
		&& tab->combin[3] == '.')
		return (tab);
	if (tab->precisions < 0)
		tab->prec_is_neg = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		tab->nbr_is_neg = 1;
	}
	indent = (tab->combin[0] == '-' || tab->nbr_is_neg == 1) ? 1 : 0;
	display_d(tab, nbr, ft_nbrlen(nbr), indent);
	return (tab);
}