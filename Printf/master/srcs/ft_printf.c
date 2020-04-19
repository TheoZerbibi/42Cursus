/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:19 by thzeribi          #+#    #+#             */
/*   Updated: 2020/04/19 04:07:27 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO:		conversion : p, u, x, X
** FIXME:		conversion : d
** WIP:			conversion : d, i
** FINISH:	conversion : c, s + parsing (conversion + flags)
*/

/*
**	functions : ft_init
**	description : TODO:
*/

t_tab	*ft_init(t_tab *tab)
{
	tab->i = 0;
	tab->len = 0;
	tab->convert_list = "cspdiuxX%";
	tab->combin_list = "-0*";
	tab->s_parse = (char *)tab->str;
	tab->s_copy = (char *)tab->str;
	return (tab);
}

/*
**	functions : ft_printf
**	description : TODO:
*/

int		ft_printf(const char *str, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->str = str;
	tab = ft_init(tab);
	if (str)
	{
		va_start(tab->args, str);
		tab->len = ft_parser(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
