/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 02:34:15 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 08:44:02 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display_s() [Static Function] :
**				Call by print_s(), this function
**				will display the calculated elements in print_s().
**				@param t_tab *tab
**				@return tab
*/

static t_tab	*display_s(t_tab *tab, char *str)
{
	int len;

	len = 0;
	if (tab->width == -1 && tab->combin[3] == '.')
		return (tab);
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

/*
**	print_s() :
**				Call by select_flag() when current flag is `s`.
**				This threat `s` flag, mainly used to prepare display
**				It will call the display_s() for general display
**				@param t_tab *tab
**				@return tab
*/

t_tab			*print_s(t_tab *tab)
{
	char		*str;
	int			len;

	len = 0;
	str = va_arg(tab->args, char *);
	if (tab->precisions && str)
		str = ft_strndup(str, tab->precisions);
	else if (!tab->precisions && str)
		str = ft_strdup(str);
	else if (tab->precisions && !str)
		str = ft_strndup("(null)", tab->precisions);
	else if (!tab->precisions && !str)
		str = ft_strdup("(null)");
	if (tab->width == 0 && tab->precisions == 0 && tab->combin[3] == '.')
	{
		free(str);
		return (tab);
	}
	display_s(tab, str);
	return (tab);
}
