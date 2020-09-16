/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 06:33:00 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 08:44:39 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display_x() [Static Function] :
**				Call by print_x(), this function
**				will display the calculated elements in print_x().
**				@param t_tab *tab & long int nbr, int blank, int upper [BOOLEAN]
**					int upper :
**						[FALSE](0)	the result will be lowercase [x]
**						[TRUE](1)		the result will be uppercase [X]
*/

static void	display_x(t_tab *tab, long int nbr, int blank, int upper)
{
	int len;

	len = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	if (tab->width_is_neg == 0 && tab->combin[1] != '0')
		display(tab, ' ', tab->width - blank, FALSE);
	if (tab->prec_is_neg == 0 && tab->combin[0] != '-' && tab->precisions >= 0)
	{
		if (tab->combin[1] == '0' && tab->precisions == 0)
			display(tab, '0', tab->width - len, FALSE);
		else
			display(tab, '0', tab->precisions - len, FALSE);
	}
	else
		blank = len;
	ft_putlnbr_base(nbr, BASE, upper, TRUE);
	if (tab->width_is_neg == 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, FALSE);
	else if (tab->width_is_neg == 1 && tab->combin[0] == '-')
		display(tab, ' ', tab->width - len, FALSE);
}

/*
**	print_x() :
**				Call by select_flag() when current flag is `x` or `X`.
**				This threat `x` or `X` flag, mainly used to prepare display
**				and calculated tab->len.
**				It will call the display_x() for general display
**				@param t_tab *tab & int upper [BOOLEAN]
**					int upper :
**						[FALSE](0)	the result will be lowercase [x]
**						[TRUE](1)		the result will be uppercase [X]
**				@return tab
*/

t_tab		*print_x(t_tab *tab, int upper)
{
	long int	nbr;
	int			indent;
	int			len;
	int			blank;

	nbr = (unsigned)(va_arg(tab->args, unsigned int));
	if ((int)nbr < 0)
		tab->nbr_is_neg = 1;
	if (tab->width == 0 && tab->combin[3] == '.' && tab->precisions == 0
		&& nbr == 0)
		return (tab);
	indent = (tab->combin[0] == '-') ? 1 : 0;
	len = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	blank = (len <= tab->precisions && tab->precisions > 0 && tab->width > 0) ?
	tab->precisions : len;
	if (tab->width_is_neg == 1 && tab->combin[1] == '0'
		&& (tab->combin[0] == '-' || tab->nbr_is_neg == 1))
		tab->len += tab->width;
	else if (tab->width_is_neg == 1 && (tab->combin[0] == '-' ||
		tab->prec_is_neg == 0 || tab->nbr_is_neg == 1)
		&& (tab->nbr_is_neg == 1 || tab->combin[1] == '0'))
		tab->len += blank;
	else if (blank <= tab->width || tab->width_is_neg == 1)
		tab->len += tab->width;
	else
		tab->len += blank;
	display_x(tab, nbr, blank, upper);
	return (tab);
}
