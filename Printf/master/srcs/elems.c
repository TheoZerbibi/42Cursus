/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:36:42 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/05 22:18:08 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*init_printf(t_tab *tab)
{
	tab->flags = '\0';
	tab->combin[0] = '\0';
	tab->combin[1] = '\0';
	tab->combin[2] = '\0';
	tab->combin[3] = '\0';
	tab->arg_flag = '\0';
	tab->width = 0;
	tab->param = 0;
	tab->precisions = 0;
	tab->width_is_neg = 0;
	tab->prec_neg = 0;
	return (tab);
}

int		get_elems(t_tab *tab)
{
	tab->i++;
	init_printf(tab);
	parse_combin(tab);
	parse_width(tab);
	parse_precisions(tab);
	parse_convert(tab);
	if (tab->arg_flag == '\0')
	{
		//printf("Return");
		return (tab->len);
	}
	parse_elems(tab);
	return (tab->len);
}

int		ft_parser(t_tab *tab)
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
