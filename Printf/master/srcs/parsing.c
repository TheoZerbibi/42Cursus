/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:51:33 by thzeribi          #+#    #+#             */
/*   Updated: 2020/05/23 18:18:14 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_convert(t_tab *tab)
{
	size_t i;

	i = 0;
	while (CONVERT[i] == tab->s_parse[tab->i])
		i++;
	i = 0;
	while (CONVERT[i] != '\0')
	{
		if (CONVERT[i] == tab->s_parse[tab->i])
		{
			tab->arg_flag = CONVERT[i];
			break;
		}
		i++;
	}
	return (tab);
}

t_tab	*parse_precisions(t_tab *tab)
{
	while (tab->s_parse[tab->i] == '.')
	{
		tab->i++;
		tab->precisions = -1;
	}
	while (ft_isdigit(tab->s_parse[tab->i]) == 1)
	{
		tab->precisions = 0;
		tab->precisions *= 10;
		tab->precisions += (tab->s_parse[tab->i] - 48);
		tab->i++;
	}
	if (tab->s_parse[tab->i] == '*')
	{
		tab->precisions = va_arg(tab->args, int);
		if (tab->precisions < 0) {
			tab->param = -1;
			tab->precisions = -tab->precisions;
		}
		tab->i++;
	}
	return (tab);
}

t_tab	*parse_width(t_tab *tab)
{
	int tmp;
	while (ft_isdigit(tab->s_parse[tab->i]) == 1)
	{
		tab->width *= 10;
		tab->width += (tab->s_parse[tab->i] - 48);
		tab->i++;
	}
	if (tab->combin[3] == '*')
	{
		tmp = va_arg(tab->args, int);
		if (tmp < 0)
		{
			tab->width_is_neg = 1;
			tab->width = tmp * -1;
		}
		else
			tab->width = tmp;
	}
	return (tab);
}

t_tab	*parse_combin(t_tab *tab)
{
	int i;

	i = 0;
	while (COMBINE[i] != '\0')
	{
		while (COMBINE[i] == tab->s_parse[tab->i])
		{
			while(tab->s_parse[tab->i] == '-' && tab->i++)
				tab->combin[0] = '-';
			while(tab->s_parse[tab->i] == '0' && tab->i++)
				tab->combin[1] = '0';
			while(tab->s_parse[tab->i] == '*' && tab->i++)
					tab->combin[3] = '*';
			i = 0;
		}
		i++;
	}
	return (tab);
}
