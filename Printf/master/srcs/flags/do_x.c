/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 06:33:00 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/16 16:38:11 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	display_x_space_before(t_tab *tab, int len, long int nbr, int blank)
{
	if (!tab->width_is_neg && tab->combin[0] != '-' && len < tab->width)
	{
		if (tab->combin[1] == '0' && tab->combin[3] != '.')
			;
		else
		{
			if (tab->prec_is_neg && tab->combin[1] == '0')
				;
			else if ((tab->prec_null || !tab->precisions)
			&& nbr == 0 && tab->combin[3] == '.')
				;
			else
			{
				blank = len;
				if (len < tab->precisions && !tab->prec_is_neg)
					blank = tab->precisions;
				display(tab, ' ', tab->width - blank, TRUE);
			}
		}
	}
	return (blank);
}

static int	display_x_zero_before(t_tab *tab, long int nbr, int len, int blank)
{
	if (!tab->prec_is_neg)
	{
		if ((!tab->precisions && nbr == 0 && !tab->prec_null)
		|| (tab->width_is_neg && tab->prec_null))
			;
		else if (tab->combin[1] == '0' && tab->combin[3] != '.')
			display(tab, '0', tab->width - (len + tab->char_display), TRUE);
		else
			display(tab, '0', tab->precisions - len, TRUE);
	}
	else if (tab->precisions >= 0 && tab->prec_is_neg
	&& tab->combin[1] == '0' && !tab->width_is_neg)
		display(tab, '0', tab->width - len, TRUE);
	else
		blank = len;
	return (blank);
}

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
	blank = display_x_space_before(tab, len, nbr, blank);
	blank = display_x_zero_before(tab, nbr, len, blank);
	if ((tab->prec_null || !tab->precisions)
	&& nbr == 0 && tab->combin[3] == '.')
	{
		display(tab, ' ', tab->width, TRUE);
		return ;
	}
	tab->len += ft_putlnbr_base(nbr, BASE, upper, TRUE);
	if (tab->width_is_neg == 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->combin[0] == '-')
	{
		if (!tab->prec_is_neg && tab->precisions >= 0 && tab->combin[3] == '.')
			display(tab, ' ', tab->width - blank, TRUE);
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
	if (!tab->width && tab->combin[3] == '.' && !tab->precisions && nbr == 0)
		return (tab);
	width = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	blank = (width <= tab->precisions && tab->precisions && tab->width >= 0)
		? tab->precisions : width;
	display_x(tab, nbr, blank, upper);
	return (tab);
}
