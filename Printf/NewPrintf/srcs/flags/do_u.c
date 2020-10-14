/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 03:11:13 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/14 22:51:10 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		display_u(t_tab *tab, long int nbr, int width)
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
		return ;
	}
	u_utils_positive(tab, width, blank);
	u_utils_positive_print(tab, nbr, width, blank);
}

t_tab		*print_u(t_tab *tab)
{
	long int		nbr;
	int				width;

	nbr = (unsigned long)(va_arg(tab->args, unsigned int));
	printf("%ld", nbr);
	if (nbr == 0 && tab->precisions < 0)
	{
		display(tab, ' ', tab->width, 1);
		return (tab);
	}
	width = ft_nbrlen(nbr);
	if (tab->precisions < 0)
		tab->prec_is_neg = 1;
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
		tab->precisions = tab->width;
	display_u(tab, nbr, width);
	return (tab);
}
