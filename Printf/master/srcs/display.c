/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/24 07:00:58 by thzeribi         ###   ########.fr       */
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

void		display_c(t_tab *tab, char c)
{
	tab->len += 1;
	ft_putchar(c);
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

t_tab		*display_u(t_tab *tab, long int nbr, int len)
{
	print_positive(tab, nbr, len);
	return (tab);
}
