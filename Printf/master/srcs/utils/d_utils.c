/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:04:20 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/17 13:19:29 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		d_utils_minus_print_before(t_tab *tab, int width)
{
	if ((!tab->prec_is_neg || tab->combin[1] == '0') && (!tab->width_is_neg
	|| !tab->prec_is_neg))
	{
		if (tab->prec_is_neg && tab->precisions >= tab->width)
			width = tab->width + tab->nbr_len;
		if (tab->nbr_len <= 2 && tab->prec_is_neg
		&& tab->precisions > tab->width)
			width -= 2;
		if (tab->nbr_len + tab->precisions - width == 0)
			display(tab, '0', tab->precisions - tab->nbr_len, TRUE);
		else if (!tab->prec_is_neg || tab->width > tab->nbr_len)
			display(tab, '0', tab->precisions - width, TRUE);
	}
	return (width);
}

static t_tab	*d_utils_minus_print_after(t_tab *tab, int already_neg,
char neg_char)
{
	if ((!tab->prec_is_neg || tab->nbr_is_neg) && !already_neg
	&& tab->nbr_is_neg)
	{
		tab->len += 1;
		tab->char_display += 1;
		write(1, &neg_char, 1);
	}
	return (tab);
}

static void		d_utils_minus_print_space(t_tab *tab, long int nbr, int width,
int blank)
{
	if (tab->char_display >= tab->width || tab->nbr_len >= tab->width)
		return ;
	if (tab->width > 0 && tab->precisions == 0 && (tab->combin[0] == '-'
	|| tab->nbr_is_neg)
		&& tab->width_is_neg)
		display(tab, ' ', tab->width - tab->char_display, TRUE);
	else if (tab->combin[0] == '-' && !tab->nbr_is_neg)
	{
		if (((tab->precisions - width) + ft_nbrlen(nbr)) == tab->precisions
		&& !tab->width)
			;
		else if (tab->width < tab->precisions)
			display(tab, ' ', tab->precisions - tab->char_display, TRUE);
		else
			display(tab, ' ', tab->width - tab->char_display, TRUE);
	}
	else if (tab->combin[0] == '-' && tab->nbr_is_neg)
		(tab->prec_is_neg) ? display(tab, ' ', tab->width - tab->nbr_len, TRUE)
		: display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->nbr_is_neg && tab->width_is_neg && tab->prec_is_neg)
		display(tab, ' ', tab->width - (ft_nbrlen(nbr) + 1), TRUE);
	else if (tab->nbr_is_neg && tab->width && tab->width_is_neg
	&& (tab->nbr_len + (tab->precisions - width) < tab->width))
		display(tab, ' ', tab->width - tab->char_display, TRUE);
}

/*
**	d_utils_minus() :
**				Call first by print_minus() when nbr is negative
**				or if there is the flag `-`.
**				This function will start display the calculated elements
**				done before.
**
**			@param t_tab *tab, int blank, char neg_char, int already_neg
**			@return tab
*/

t_tab			*d_utils_minus(t_tab *tab, int blank, char neg_char,
int already_neg)
{
	if (!tab->prec_is_neg && (tab->precisions || (!tab->precisions
	&& tab->combin[3] == '.')) && tab->combin[0] != '-' && !tab->width_is_neg)
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->combin[1] != '0' && !tab->width_is_neg
	&& tab->combin[0] != '-')
		display(tab, ' ', tab->width - tab->nbr_len, TRUE);
	else if (!tab->precisions && !tab->width_is_neg && tab->combin[1] == '0'
	&& tab->combin[0] != '-')
	{
		tab->len += 1;
		tab->char_display += 1;
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, TRUE);
		already_neg = 1;
	}
	else if (tab->prec_is_neg && tab->combin[0] != '-' && !tab->width_is_neg)
	{
		tab->len += 1;
		tab->char_display += 1;
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, TRUE);
		already_neg = 1;
	}
	d_utils_minus_print_after(tab, already_neg, neg_char);
	return (tab);
}

/*
**	d_utils_minus_print() :
**				Call secondly by print_minus() when nbr is negative
**				or if there is the flag `-`.
**				This function will continue and finish display.
**
**			@param t_tab *tab, long int nbr, int width, int blank
**			@return void function, no values ​​return
*/

void			d_utils_minus_print(t_tab *tab, long int nbr, int width,
int blank)
{
	width = d_utils_minus_print_before(tab, width);
	tab->nbr_len -= (tab->nbr_is_neg) ? 1 : 0;
	if (!tab->precisions && nbr == 0 && tab->combin[3] == '.')
		display(tab, ' ', 1, FALSE);
	else if (nbr != (-9223372036854775807 - 1))
	{
		tab->char_display += tab->nbr_len;
		ft_putnbrmax_fd(nbr, 1);
	}
	else if ((tab->len += 18) > 0)
	{
		tab->char_display += tab->nbr_len;
		write(1, "9223372036854775808", 19);
	}
	tab->len += tab->nbr_len;
	tab->nbr_len += (tab->nbr_is_neg) ? 1 : 0;
	if (((tab->precisions - width) + tab->nbr_len) <= tab->precisions
	&& tab->precisions > tab->width)
	{
		display(tab, ' ', tab->width - tab->char_display, TRUE);
		return ;
	}
	d_utils_minus_print_space(tab, nbr, width, blank);
}
