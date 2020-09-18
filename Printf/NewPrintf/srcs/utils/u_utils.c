/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 03:23:48 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/18 03:30:43 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	u_utils_positive(t_tab *tab, int width, int blank)
{
	if (tab->width_is_neg == 0)
	{
		if (tab->combin[3] == '.'
			&& tab->combin[2] != '*' && tab->prec_is_neg == 0)
		{
			if (tab->prec_is_neg == 1)
				display(tab, ' ', tab->width - width, TRUE);
			else
				display(tab, ' ', tab->width - blank, TRUE);
		}
	}
}

void	u_utils_positive_print(t_tab *tab, long int nbr,
int width, int blank)
{
	if (tab->prec_is_neg == 0 && tab->combin[1] == '0')
	{
		if (tab->combin[3] == '.' && tab->prec_is_neg == 0 && (int)nbr >= 0)
			display(tab, '0', tab->precisions - width, 0);
		else if (tab->combin[3] == '.' && tab->combin[2] == '*'
			&& tab->prec_is_neg == 1 && tab->width_is_neg == 0)
		{
			width = tab->width - ft_nbrlen(nbr);
			display(tab, '0', width, TRUE);
		}
	}
	if (nbr != (-2147483647 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 9) > 0)
		write(1, "2147483647", 10);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, TRUE);
}