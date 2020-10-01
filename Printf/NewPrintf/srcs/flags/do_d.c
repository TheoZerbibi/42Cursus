/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:02:09 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/01 17:26:08 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	print_positive() [Static Function] :
**				Call by display_d() when nbr is positive.
**				This function will calculate and start to display
**				and call d_utils_positive_print() for the rest of the display
**
**			@param t_tab *tab, long int nbr, int width
**			@return void function, no values ​​return
*/

static void		print_positive(t_tab *tab, long int nbr, int width)
{
	int		blank;

	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	if ((blank = width) && width <= tab->precisions
		&& tab->precisions >= 0 && !tab->prec_is_neg)
		blank = tab->precisions;
	if (nbr == 0 && !tab->precisions && tab->combin[3] == '.'
		&& tab->combin[1] != '0')
	{
		if (tab->width > 0)
			display(tab, ' ', tab->width, TRUE);
		else
			tab->len -= 1;
		return ;
	}
	if (!tab->width_is_neg && tab->precisions && !tab->prec_is_neg)
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->width && tab->combin[3] != '.'
		&& tab->combin[2] != '*' && tab->combin[1] != '0')
		display(tab, ' ', tab->width - blank, TRUE);
	else if (!tab->width_is_neg && tab->combin[1] != '0')
		display(tab, ' ', tab->width - blank, TRUE);
	else if ((!tab->precisions && !tab->prec_null) && tab->combin[1] == '0' && tab->width && !tab->width_is_neg)
		display(tab, ' ', tab->width - blank, TRUE);
	d_utils_positive_print(tab, nbr, width, blank);
}

/*
**	print_minus() [Static Function] :
**				Call by display_d() when nbr is negative
**				or if there is the flag `-`
**				This function will calculate and call 
**				d_utils_negative() and d_utils_minus_print
**				for the rest of the display
**
**			@param t_tab *tab, long int nbr, int width
**			@return void function, no values ​​return
*/

static void		print_minus(t_tab *tab, long int nbr, int width, int is_neg)
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

/*
**	display_d() [Static Function] :
**				Call by print_d(), this function
**				will will separate the rest of
**				the operations into two parts.
**				- printf_minus() for all minus number.
**					or if there is the flag `-`
**				- print_positive() for all positive number.
**
**			@param t_tab *tab & long int nbr, int width, int is_neg [BOOLEAN]
**				int is_neg :
**					[FALSE](0)	- the nbr is positive or flag `-` is not present.
**					[TRUE](1)		- the nbr is negative or flag `-` is present.
**			@return tab
*/

static t_tab	*display_d(t_tab *tab, long int nbr, int width, int is_neg)
{
	if (is_neg)
		print_minus(tab, nbr, width, is_neg);
	else
		print_positive(tab, nbr, width);
	return (tab);
}

/*
**	print_d() :
**				Call by select_flag() when current flag is `d` or `i`.
**				This function threat `d` or `i` flag, mainly used to prepare
**				the display. It will call the display_d()
**				for general display.
**
**			@param t_tab *tab
**			@return tab
*/

t_tab			*print_d(t_tab *tab)
{
	long int	nbr;
	int			indent;

	nbr = (int)(va_arg(tab->args, int));
	if (tab->space_after)
		display(tab, ' ', 1, TRUE);
	if (nbr == 0 && ((tab->precisions == 1 && tab->prec_null) || (!tab->precisions && tab->combin[3] == '.')))
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
