/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:02 by thzeribi          #+#    #+#             */
/*   Updated: 2020/03/12 06:57:04 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_elems(t_tab *tab)
{
	char *flag;

	flag = &tab->arg_flag;
	//printf("\nARG %c\n", *flag);
	if (*flag == 'c' || *flag == '%')
		print_c(tab);
	else if (*flag == 's')
		print_s(tab);
	return (tab);
}
