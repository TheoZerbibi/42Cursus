/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:02 by thzeribi          #+#    #+#             */
/*   Updated: 2020/06/09 15:49:13 by thzeribi         ###   ########.fr       */
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
	else if (*flag == 'x' || *flag == 'X')
		print_x(tab);
	return (tab);
}
