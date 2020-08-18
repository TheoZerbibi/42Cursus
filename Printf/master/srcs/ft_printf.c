/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:19 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/18 22:51:14 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO:		conversion : /
** FIXME:		conversion : d (0 test 3), Xx (all good until Test 11,
**						Test 9 bad size)
** WIP:			conversion : xX, u
** FINISH:	conversion : i ,c, s, p + parsing (conversion + flags)
*/

/*
**	functions : ft_init
**	description : TODO:
*/

static t_tab	ft_init(t_tab *tab, const char *str)
{
	tab->i = 0;
	tab->len = 0;
	tab->str = str;
	tab->s_parse = (char *)tab->str;
	tab->s_copy = (char *)tab->str;
	return (*tab);
}

/*
**	functions : ft_printf
**	description : TODO:
*/

int				ft_printf(const char *str, ...)
{
	t_tab tab;

	ft_init(&tab, str);
	if (!str)
		return (ERROR);
	else
	{
		va_start(tab.args, str);
		tab.len = ft_parser(&tab);
		va_end(tab.args);
	}
	return (tab.len);
}
