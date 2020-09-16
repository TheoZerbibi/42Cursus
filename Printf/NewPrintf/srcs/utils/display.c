/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 03:43:10 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 11:14:50 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	display() :
**				General function for display
**
**			@param t_tab *tab & int c & int len, int update_len [BOOLEAN]
**				int update_len :
**					[FALSE](0)	int len ​​will not be added to tab->len
**					[TRUE](1)		int len ​​will be added to tab->len
**			@return tab
*/

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
