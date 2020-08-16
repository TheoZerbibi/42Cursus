/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:19 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/15 23:52:45 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO:		conversion : u
** FIXME:		conversion : d (0 test 3), Xx (all good until Test 9)
** WIP:			conversion : xX, p
** FINISH:	conversion : i ,c, s + parsing (conversion + flags)
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

int		ft_printf(const char *str, ...)
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
