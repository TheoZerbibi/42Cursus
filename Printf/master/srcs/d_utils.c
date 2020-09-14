/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:43:16 by thezerbibi        #+#    #+#             */
/*   Updated: 2020/09/14 22:53:39 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*d_utils_minus(t_tab *tab, int blank,
	char neg_char, int already_neg)
{
	if (tab->param == 0 && tab->precisions != 0)
		display(tab, ' ', tab->width - blank, 0);
	else if (tab->param == 0 && tab->combin[1] != '0' && tab->width_is_neg != 1)
		display(tab, ' ', tab->width - blank, 0);
	else if (tab->precisions == 0 && tab->width_is_neg == 0
		&& tab->combin[1] == '0')
	{
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, 0);
		already_neg = 1;
	}
	else if (tab->param == -1)
	{
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, 0);
		already_neg = 1;
	}
	if (tab->param == 0 && already_neg == 0 && tab->nbr_is_neg == 1)
		write(1, &neg_char, 1);
	else if (already_neg == 0)
		tab->len -= 1;
	return (tab);
}

void	d_utils_minus_print(t_tab *tab, long int nbr, int width, int blank)
{
	display(tab, '0', tab->precisions - width, 0);
	if (nbr != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (tab->width > 0 && tab->precisions == 0 && tab->combin[0] == '-' &&
		tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
}

void	d_utils_positive_print(t_tab *tab, long int nbr,
int width, int blank)
{
	if (tab->prec_neg == 0 && tab->combin[1] == '0')
	{
		if (tab->arg_flag != 'u' && tab->width > 0)
			display(tab, '0', tab->precisions - width, 0);
		else if (tab->arg_flag == 'u')
		{
			if (tab->combin[3] == '.' && tab->param == 0 && (int)nbr >= 0)
				display(tab, '0', tab->precisions - width, 0);
			else if (tab->combin[3] == '.' && tab->combin[2] == '*'
				&& tab->param == -1 && tab->width_is_neg == 0)
			{
				width = tab->width - ft_nbrlen(nbr);
				display(tab, '0', width, 0);
			}
		}
	}
	if (nbr != (-2147483647 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 9) > 0)
		write(1, "2147483647", 10);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
}

void	d_utils_positive(t_tab *tab, int width, int blank)
{
	if (tab->width_is_neg == 0)
	{
		if (tab->arg_flag == 'u' && tab->combin[3] == '.'
			&& tab->combin[2] != '*' && tab->param == 0)
		{
			if (tab->prec_neg == 1)
				display(tab, ' ', tab->width - width, 0);
			else
				display(tab, ' ', tab->width - blank, 0);
		}
		else if (tab->arg_flag != 'u')
			display(tab, ' ', tab->width - blank, 0);
	}
}
