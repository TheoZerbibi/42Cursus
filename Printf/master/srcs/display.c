/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:48:44 by thzeribi          #+#    #+#             */
/*   Updated: 2020/05/09 23:08:39 by thzeribi         ###   ########.fr       */
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
	//printf("%ld - %d = %ld\n", tab->precisions, width, (tab->precisions - width));
	int			blank;
	char		neg_char;

	nbr *= (nbr != (-9223372036854775807 - 1)) ? 1 : -1;
	neg_char = (is_neg) ? '-' : '\0';
	blank = width;
	if (width <= tab->precisions && tab->precisions >= 0)
		blank = tab->precisions;
	if (neg_char)
		blank++;
	tab->len += (blank <= tab->width) ? tab->width : blank;
	if (is_neg)
		display(tab, ' ', tab->width - blank, 0);
	if (neg_char)
		write(1, &neg_char, 1);
	//printf("%ld - %d = %ld\n", tab->precisions, width, (tab->precisions - width));
	display(tab, '0', tab->precisions - width, 0);
	if (nbr != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(nbr, 1);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (!is_neg && tab->precisions < 0)
		display(tab, ' ', tab->width - blank, 0);
	return (tab);
}
