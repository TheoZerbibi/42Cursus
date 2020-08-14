/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:02 by thzeribi          #+#    #+#             */
/*   Updated: 2020/08/14 02:25:10 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_elems(t_tab *tab)
{
	char *flag;

	flag = &tab->arg_flag;
	if (*flag == 'c' || *flag == '%')
		print_c(tab);
	else if (*flag == 's')
		print_s(tab);
	else if (*flag == 'd' || *flag == 'i')
		print_d(tab);
	else if (*flag == 'x')
		print_x(tab, 0);
	else if (*flag == 'X')
		print_x(tab, 1);
	else if (*flag == 'p')
		print_p(tab);
	return (tab);
}
