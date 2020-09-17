/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 06:33:00 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/17 08:55:18 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display_x() [Static Function] :
**				Call by print_x(), this function
**				will display the calculated elements in print_x().
**
**			@param t_tab *tab & long int nbr, int blank, int upper [BOOLEAN]
**				int upper :
**					[FALSE](0)	the result will be lowercase [x]
**					[TRUE](1)		the result will be uppercase [X]
**			@return void function, no values ​​return
*/

static void	display_x(t_tab *tab, long int nbr, int blank, int upper)
{
	int len;

	len = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	if (tab->width_is_neg == 0 && tab->combin[1] != '0'
		&& tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, TRUE);
	if (tab->prec_is_neg == 0 && tab->precisions >= 0)
	{
		if (tab->combin[1] == '0' && tab->precisions == 0)
			display(tab, '0', tab->width - len, TRUE);
		else
			display(tab, '0', tab->precisions - len, TRUE);
	}
	else
		blank = len;
	tab->len += ft_putlnbr_base(nbr, BASE, upper, TRUE);
	if (tab->width_is_neg == 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->combin[0] == '-')
	{
		if (tab->prec_is_neg == 0 && tab->precisions >= 0
			&& tab->combin[3] == '.')
			display(tab, ' ', tab->width - (len + 2), TRUE);
		else
			display(tab, ' ', tab->width - len, TRUE);
	}
}

/*
**	print_x() :
**				Call by select_flag() when current flag is `x` or `X`.
**				This function threat `x` or `X` flag, mainly used
**				to prepare the display.
**				It will call calc_len() for calculated the final len.
**
**			@param t_tab *tab & int upper [BOOLEAN]
**				int upper :
**					[FALSE](0)	- the result will be lowercase [x]
**					[TRUE](1)		- the result will be uppercase [X]
**			@return tab
*/

t_tab		*print_x(t_tab *tab, int upper)
{
	long int	nbr;
	int			width;
	int			blank;

	nbr = (unsigned)(va_arg(tab->args, unsigned int));
	if ((int)nbr < 0)
		tab->nbr_is_neg = 1;
	if (tab->width == 0 && tab->combin[3] == '.' && tab->precisions == 0
		&& nbr == 0)
		return (tab);
	width = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	blank = (width <= tab->precisions && tab->precisions > 0 && tab->width >= 0)
		? tab->precisions : width;
	display_x(tab, nbr, blank, upper);
	return (tab);
}
