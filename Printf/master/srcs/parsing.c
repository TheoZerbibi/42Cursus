/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:51:33 by thzeribi          #+#    #+#             */
/*   Updated: 2020/03/05 05:12:08 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_convert(t_tab *tab)
{
	size_t i;

	i = 0;
	while (tab->convert_list[i] == tab->s_parse[tab->i])
		i++;
	if (tab->convert_list[i+1] != tab->s_parse[tab->i]
		&& tab->convert_list[i+1] != '\0')
	{
		tab->i++;
		parse_convert(tab);
	}
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
	//printf("\nTAB->COMBIN : %c\n", tab->combin[3]);
	//printf("\nTAB->ARGS = %d\n",va_arg(tab->args, int));
	if (tab->combin[3] == '*')
	{
		tab->precisions = va_arg(tab->args, int);
		if (tab->precisions < 0)
			tab->precisions = -tab->precisions;
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
	if (tab->combin[2] == '*')
	{
		tmp = va_arg(tab->args, int);
		if (tmp <= 0)
			tab->precisions = -1;
		else
			tab->precisions = tmp;
	}
	if (tab->combin[3] == '*')
	{
		tmp = va_arg(tab->args, int);
		if (tmp < 0)
		{
			tab->combin[0] = '-';
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
	while (tab->combin_list[i] != '\0')
	{
		while (tab->combin_list[i] == tab->s_parse[tab->i])
		{
			while(tab->s_parse[tab->i] == '-' && tab->i++)
				tab->combin[0] = '-';
			while(tab->s_parse[tab->i] == '0' && tab->i++)
				tab->combin[1] = '0';
			while(tab->s_parse[tab->i] == '*' && tab->i++)
			{
				if (tab->combin[2] == '*')
					tab->combin[2] = '*';
				else
					tab->combin[3] = '*';
			}
			i = 0;
		}
		i++;
	}
	return (tab);
}
