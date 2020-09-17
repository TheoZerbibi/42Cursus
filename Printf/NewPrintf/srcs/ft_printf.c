/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:16:52 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/17 08:48:15 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	ft_init() [Static Function ]:
**			Call by ft_printf(), this function is for init structure for parsing
**
**		@param t_tab *tab & const char *str
**		@return *tab
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
**	ft_printf() :
**			This function is the main function for PrintF
**
**		@param char *str & va_arg
**		@return tab.len
**
**	NOTE : check man printf
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
