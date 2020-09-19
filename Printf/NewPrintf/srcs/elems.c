/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:18:16 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/19 06:04:45 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	init_printf() [Static Function] :
**				Call by get_elems(), this function init structure
**				for the proper functioning of printf
**
**			@param t_tab *tab
**			@return tab.len
*/

static t_tab	*init_printf(t_tab *tab)
{
	tab->combin[0] = '\0';
	tab->combin[1] = '\0';
	tab->combin[2] = '\0';
	tab->combin[3] = '\0';
	tab->width = 0;
	tab->precisions = 0;
	tab->width_is_neg = 0;
	tab->prec_is_neg = 0;
	tab->prec_null = 1;
	tab->nbr_is_neg = 0;
	return (tab);
}

/*
**	select_flag() [Static Function] :
**				Call fifth by get_elems(), this function find the current flag
**				and call and calls the appropriate function.
**
**			@param t_tab tab
**			@return tab.len
*/

static t_tab	*select_flag(t_tab *tab)
{
	char *flag;

	flag = &tab->flag;
	if (*flag == 'c' || *flag == '%')
		print_c(tab);
	else if (*flag == 's')
		print_s(tab);
	else if (*flag == 'p')
		print_p(tab);
	else if (*flag == 'x')
		print_x(tab, FALSE);
	else if (*flag == 'X')
		print_x(tab, TRUE);
	else if (*flag == 'd' || *flag == 'i')
		print_d(tab);
	else if (*flag == 'u')
		print_u(tab);
	return (tab);
}

/*
**	get_elems() [Static Function] :
**				Call when ft_parser find a '%'.
**				This function will call all parsing function
**
**			@param t_tab tab
**			@return tab.len
*/

static int		get_elems(t_tab *tab)
{
	tab->i++;
	init_printf(tab);
	parse_combin(tab);
	parse_width(tab);
	parse_precisions(tab);
	parse_flags(tab);
	select_flag(tab);
	return (tab->len);
}

/*
**	ft_parser() :
**				Call by ft_printf(), this function read a copy
**				of original string (s_copy) and write by
**				default (default = no '%').
**
**			@param t_tab tab
**			@throws 0 if string just contain `%`
**			@return tab.len
*/

int				ft_parser(t_tab *tab)
{
	if (ft_strcmp(tab->s_copy, "%") == 0)
		return (0);
	while (tab->s_copy[tab->i])
	{
		if (tab->s_copy[tab->i] == '%')
			get_elems(tab);
		else
		{
			write(1, &tab->s_copy[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
