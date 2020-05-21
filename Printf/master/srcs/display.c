/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/05/21 12:18:37 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display(t_tab *tab, int c, int len, int update_len)
{
	char *str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = ft_strnew(len)))
			exit(ERROR);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

void	display_c(t_tab *tab, char c)
{
		tab->len += 1;
		ft_putchar(c);
}

t_tab	*display_d(t_tab *tab, long int nbr, int width, int is_neg)
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
	if (is_neg && tab->param == 0 && tab->precisions != 0 )
		display(tab, ' ', tab->width - blank, 0);
	else if (tab->precisions == 0 && tab->width_is_neg == 0)
	{
		write(1, &neg_char, 1);
		display(tab, '0', tab->width - blank, 0);
		already_neg = 1;
	}
	else if (tab->param == -1) {
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
	if (tab->width > 0 && tab->precisions == 0 && tab->combin[0] == '-' && tab->width_is_neg == 1)
		display(tab, ' ', tab->width - blank, 0);
	return (tab);
}
