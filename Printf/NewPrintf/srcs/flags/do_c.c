/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 06:17:55 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 06:30:34 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	print_c() :
**				Call by select_flag() when current flag is `c` or `%`.
**				This threat `c` or `%` flag, is used to prepared and show display
**				@param t_tab *tab
**				@return tab
*/

t_tab		*print_c(t_tab *tab)
{
	char c;

	c = (tab->flag == '%') ? '%' : (char)va_arg(tab->args, int);
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
		display(tab, '0', tab->width - 1, 1);
	else if (tab->width_is_neg == 0 && tab->combin[0] != '-')
		display(tab, ' ', tab->width - 1, 1);
	if (tab->width_is_neg == -1)
		display(tab, ' ', 1, 0);
	else
	{
		tab->len += 1;
		ft_putchar(c);
	}
	if (tab->width_is_neg == 1 || tab->combin[0] == '-')
		display(tab, ' ', tab->width - 1, 1);
	return (tab);
}