/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:04:20 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/18 04:46:03 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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


t_tab	*d_utils_minus(t_tab *tab, int blank, char neg_char,
int already_neg)
{
	if (tab->prec_is_neg == 0 && tab->precisions != 0 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->prec_is_neg == 0 && tab->combin[1] != '0'
		&& tab->width_is_neg != 1 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->precisions == 0 && tab->width_is_neg == 0
		&& tab->combin[1] == '0' && tab->combin[0] != '-')
	{
		tab->len += 1;
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, TRUE);
		already_neg = 1;
	}
	else if (tab->prec_is_neg == 1 && tab->combin[0] != '-')
	{
		tab->len += 1;
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, TRUE);
		already_neg = 1;
	}
	if ((tab->prec_is_neg == 0 || tab->nbr_is_neg == 1)
		&& already_neg == 0 && tab->nbr_is_neg == 1)
	{
		tab->len += 1;
		write(1, &neg_char, 1);
	}
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

void	d_utils_minus_print(t_tab *tab, long int nbr, int width, int blank)
{
	display(tab, '0', tab->precisions - width, TRUE);
	if (nbr != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	tab->len += ft_nbrlen(nbr);
	if (tab->width > 0 && tab->precisions == 0 && (tab->combin[0] == '-'
		|| tab->nbr_is_neg == 1) && tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, TRUE);
	else if (tab->combin[0] == '-' && tab->nbr_is_neg == 0)
		display(tab, ' ', tab->width - (blank - 1), TRUE);
}

/*
**	d_utils_positive_print() :
**				Call by print_positive() when nbr is positive.
**				This function will display the calculated elements
**				done before.
**
**			@param t_tab *tab, long int nbr, int width, int blank
**			@return void function, no values ​​return
*/

void	d_utils_positive_print(t_tab *tab, long int nbr,
int width, int blank)
{
	int already_print;

	already_print = 0;
	if (tab->prec_is_neg == 0 && (tab->combin[1] == '0' || tab->width == 0)
		&& tab->combin[0] != '-' && tab->precisions > 0)
	{
		already_print = 1;
		display(tab, '0', tab->precisions - width, TRUE);
	}
	else if (tab->precisions == 0 && tab->combin[1] == '0'
		&& tab->combin[0] != '-' && tab->width_is_neg == 0)
	{
		already_print = 1;
		display(tab, '0', tab->width - width, TRUE);
	}
	if (already_print == 0)
		display(tab, '0', tab->precisions - width, TRUE);
	if (nbr != (-2147483647 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 9) > 0)
		write(1, "2147483647", 10);
	tab->len += ft_nbrlen(nbr);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, TRUE);
}
