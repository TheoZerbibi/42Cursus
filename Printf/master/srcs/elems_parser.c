/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:02 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/31 03:22:21 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_elems(t_tab *tab)
{
	char *flag;

	flag = &tab->arg_flag;
	if (*flag == 'c')
		print_c(tab);
	else if (*flag == 's')
		print_s(tab);
	return (tab);
}
