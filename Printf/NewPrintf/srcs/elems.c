/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:18:16 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 00:57:10 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_tab	*init_printf(t_tab *tab)
{
	tab->combin[0] = '\0';
	tab->combin[1] = '\0';
	tab->combin[2] = '\0';
	tab->combin[3] = '\0';
	tab->width = 0;
	tab->precisions = 0;
	tab->width_is_neg = 0;
	tab->prec_neg = 0;
	tab->nbr_is_neg = 0;
	return (tab);
}

static t_tab	*select_flag(t_tab *tab)
{
	char *flag;

	flag = &tab->flag;
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
	else if (*flag == 'u')
		print_u(tab);
	return (tab);
}

static int	get_elems(t_tab tab)
{
	tab.i++;
	init_printf(&tab);
	parse_combin(&tab);
	parse_width(&tab);
	parse_precisions(&tab);
	parse_flags(&tab);
	select_flag(&tab);
	return (tab.len);
}

int		ft_parser(t_tab tab)
{
	if (ft_strcmp(tab.s_copy, "%") == 0)
		return (ERROR);
	while (tab.s_copy[tab.i])
	{
		if (tab.s_copy[tab.i] == '%')
			get_elems(tab);
		else
		{
			write(1, &tab.s_copy[tab.i], 1);
			tab.len++;
		}
		tab.i++;
	}
	return (tab.len);
}
