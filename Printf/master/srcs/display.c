/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/14 22:28:05 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display(t_tab *tab, int c, int len, int update_len)
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

t_tab		*display_s(t_tab *tab, char *str)
{
	int len;

	len = 0;
	if (str)
		len = ft_strlen(str);
	if (tab->precisions == -1)
		tab->len += tab->width;
	else
		tab->len += len;
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
		display(tab, '0', tab->width - len, 1);
	else if (tab->width_is_neg == 0 && tab->precisions != -1
		&& tab->combin[0] != '-')
		display(tab, ' ', tab->width - len, 1);
	if (tab->precisions == -1)
		display(tab, ' ', tab->width, 0);
	else
		ft_putstr(str);
	if (tab->width_is_neg == 1 || tab->combin[0] == '-')
		display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}

t_tab		*display_d(t_tab *tab, long int nbr, int width, int is_neg)
{
	if (is_neg)
		print_minus(tab, nbr, width, is_neg);
	else
		print_positive(tab, nbr, width);
	return (tab);
}

t_tab		*display_p(t_tab *tab, char *str, int indent)
{
	int			blank;
	int			width;

	width = ft_strlen(str) + 2;
	blank = width;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (!indent)
		display(tab, ' ', tab->width - blank, 0);
	write(1, "0x", 2);
	display(tab, '0', (tab->precisions - width) + 2, 1);
	ft_putstr(str);
	if (indent)
		display(tab, ' ', tab->width - blank, 0);
	free(str);
	return (tab);
}

void		display_x(t_tab *tab, long int nbr, int blank, int upper)
{
	int len;

	len = ft_putlnbr_base(nbr, BASE, upper, FALSE);
	if (tab->width_is_neg == 0 && tab->combin[1] != '0')
		display(tab, ' ', tab->width - blank, FALSE);
	if (tab->param == 0 && tab->combin[0] != '-' && tab->precisions >= 0)
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
