/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:50:20 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 06:21:30 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display_p() [Static Function] :
**				Call by print_x(), this function
**				will display the calculated elements in print_p().
**				@param t_tab *tab & char *str, int indent
**				@return tab
*/

static t_tab		*display_p(t_tab *tab, char *str, int indent)
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

/*
**	print_p() :
**				Call by select_flag() when current flag is `p`.
**				This threat `p` flag, mainly used to prepare display
**				It will call the display_p() for general display
**				@param t_tab *tab
**				@return tab
*/

t_tab		*print_p(t_tab *tab)
{
	char		*str;
	long int	nbr;
	int			indent;

	indent = 0;
	nbr = (unsigned long)(va_arg(tab->args, unsigned long int));
	indent = (tab->combin[0] == '-') ? 1 : 0;
	if (tab->combin[0] == '-' || tab->width_is_neg == 1)
		indent = 1;
	else
		indent = 0;
	if (!(str = ft_itoa_base(nbr, 16, 'a')))
		exit(ERROR);
	if (tab->combin[1] == '0' && tab->precisions == -1 && !tab->combin[0])
	{
		tab->precisions = tab->width;
		tab->width = 0;
	}
	display_p(tab, str, indent);
	return (tab);
}