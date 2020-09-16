/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 06:33:00 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 07:16:38 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		display_x(t_tab *tab, long int nbr, int blank, int upper)
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