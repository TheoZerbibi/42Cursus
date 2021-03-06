/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 02:34:15 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/16 16:10:10 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display_s() [Static Function] :
**				Call by print_s(), this function
**				will display the calculated elements in print_s().
**
**			@param t_tab *tab
**			@return tab
*/

static t_tab	*display_s(t_tab *tab, char *str, int len)
{
	if (tab->combin[1] == '0' && tab->combin[0] != '-')
		display(tab, '0', tab->width - len, TRUE);
	if (((tab->precisions && tab->prec_null)
	|| (!tab->precisions && tab->combin[3] == '.')))
	{
		tab->len -= len;
		display(tab, ' ', tab->width, TRUE);
	}
	else if (!tab->width_is_neg && tab->combin[0] != '-')
		display(tab, ' ', tab->width - len, TRUE);
	if (tab->precisions > 0 && tab->prec_null != 1)
		ft_putstr(str);
	else if (!tab->precisions && tab->prec_null && tab->combin[0] != '.')
		ft_putstr(str);
	if ((tab->width_is_neg || tab->combin[0] == '-') && (!tab->prec_null
	|| tab->combin[3] != '.') && (tab->precisions
	|| (!tab->precisions && tab->prec_null)))
		display(tab, ' ', tab->width - len, TRUE);
	free(str);
	return (tab);
}

/*
**	print_s() :
**				Call by select_flag() when current flag is `s`.
**				This function threat `s` flag, mainly used to prepare
**				the display. It will call the display_s()
**				for general display
**
**			@param t_tab *tab
**			@return tab
*/

t_tab			*print_s(t_tab *tab)
{
	char		*str;
	int			len;

	len = 0;
	str = va_arg(tab->args, char *);
	if (!tab->width && tab->precisions == 0 && tab->combin[3] == '.')
		return (tab);
	if (tab->width == -1 && tab->combin[3] == '.')
		return (tab);
	if (tab->precisions && str && !tab->prec_is_neg)
		str = ft_strndup(str, tab->precisions);
	else if ((!tab->precisions || tab->prec_is_neg) && str)
		str = ft_strdup(str);
	else if (tab->precisions && !str && !tab->prec_is_neg)
		str = ft_strndup("(null)", tab->precisions);
	else if ((!tab->precisions || tab->prec_is_neg) && !str)
		str = ft_strdup("(null)");
	if (str)
		len = ft_strlen(str);
	tab->len += len;
	display_s(tab, str, len);
	return (tab);
}
