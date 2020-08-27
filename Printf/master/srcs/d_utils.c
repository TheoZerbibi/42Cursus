/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:43:16 by thezerbibi        #+#    #+#             */
/*   Updated: 2020/08/27 23:43:43 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(long int nbr)
{
	int width;

	width = 1;
	while ((nbr /= 10) > 0)
		width++;
	return (width);
}

void	print_minus(t_tab *tab, long int nbr, int width, int is_neg)
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
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (is_neg && tab->param == 0 && tab->precisions != 0)
		display(tab, ' ', tab->width - blank, 0);
	else if (tab->precisions == 0 && tab->width_is_neg == 0)
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
	if (neg_char && tab->param == 0 && already_neg == 0)
		write(1, &neg_char, 1);
	display(tab, '0', tab->precisions - width, 0);
	if (nbr != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (tab->width > 0 && tab->precisions == 0 && tab->combin[0] == '-' &&
		tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
}

void	print_positive(t_tab *tab, long int nbr, int width)
{
	int			blank;

	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	blank = width;
	if (width <= tab->precisions && tab->precisions >= 0)
		blank = tab->precisions;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (tab->width_is_neg == 0)
		display(tab, ' ', tab->width - blank, 0);
	printf("%c", tab->arg_flag);
	if (tab->prec_neg == 0 && tab->arg_flag != 'u')
		display(tab, '0', tab->precisions - width, 0);
	else if (tab->arg_flag == 'u' && tab->combin[3] != '.')
		display(tab, '0', tab->precisions - width, 0);
	if (nbr != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
}
