/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:51:33 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/31 07:01:32 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_convert(t_tab *tab)
{
	size_t i;

	i = 0;
	while (tab->convert_list[i] != '\0')
	{
		if (tab->convert_list[i] == tab->s_parse[tab->i])
			tab->arg_flag = tab->convert_list[i];
		i++;
	}
	return (tab);
}

t_tab	*parse_precisions(t_tab *tab)
{
	while (tab->s_parse[tab->i] == '.')
	{
		tab->i++;
		tab->precisions = 0;
	}
	while (ft_isdigit(tab->s_parse[tab->i]) == 1)
	{
		tab->precisions *= 10;
		tab->precisions += (tab->s_parse[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab	*parse_width(t_tab *tab)
{
	while (ft_isdigit(tab->s_parse[tab->i]) == 1)
	{
		tab->width *= 10;
		tab->width += (tab->s_parse[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab	*parse_combin(t_tab *tab)
{
	int i;

	i = 0;
	while (tab->combin_list[i] != '\0')
	{
		while (tab->combin_list[i] == tab->s_parse[tab->i])
		{
			while(tab->s_parse[tab->i] == '-' && tab->i++)
				tab->combin[0] = '-';
			while(tab->s_parse[tab->i] == '0' && tab->i++)
				tab->combin[1] = '0';
			while(tab->s_parse[tab->i] == '*' && tab->i++)
				tab->combin[2] = '*';
			i = 0;
		}
		i++;
	}
	return (tab);
}
