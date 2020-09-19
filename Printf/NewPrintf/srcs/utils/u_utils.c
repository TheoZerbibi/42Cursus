/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 03:23:48 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/18 04:38:22 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	u_utils_positive(t_tab *tab, int width, int blank)
{
	if (tab->width_is_neg == 0 && tab->combin[0] != '-')
	{
		if (tab->combin[1] == '0' && tab->combin[3] != '.')
			return ;
		if (tab->combin[2] != '*' &&
			tab->prec_is_neg == 0)
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
	int already_print;

	already_print = 0;
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
	{
		if (tab->combin[3] == '.' && tab->prec_is_neg == 0 && (int)nbr >= 0)
		{
			already_print = 1;
			display(tab, '0', tab->precisions - width, TRUE);
		}
		else if (tab->combin[3] == '.' && tab->combin[2] == '*'
			&& tab->prec_is_neg == 1 && tab->width_is_neg == 0)
			{
				already_print = 1;
				display(tab, '0', tab->width - width, TRUE);
			}
	}
	if (already_print == 0 && tab->combin[3] != '.' && tab->combin[0] != '-' && tab->width_is_neg == 0)
	{
		if (tab->prec_null == 1 && tab->combin[1] != '0')
			;
		else
			display(tab, '0', tab->width - width, TRUE);
	}
	else if (already_print == 0 && tab->combin[0] != '-' && tab->width_is_neg == 0)
		display(tab, '0', tab->precisions - width, TRUE);
	if ((tab->precisions == 1 && tab->prec_null == 1) && tab->combin[3] == '.' && nbr == 0)
	{
		if (tab->width > 0)
			display(tab, ' ', 1, TRUE);
	}
	else
	{
			tab->len += ft_nbrlen(nbr);
		if (nbr != (-2147483647 - 1))
			ft_putnbrmax_fd(nbr, 1);
		else if ((tab->len += 9) > 0)
			write(1, "2147483647", 10);
	}
	if (tab->width_is_neg == 1 || tab->combin[0] == '-')
		display(tab, ' ', tab->width - blank, TRUE);
}