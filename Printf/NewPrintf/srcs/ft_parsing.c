/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:35:34 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/17 08:54:33 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	parse_combin() :
**				Call first by get_elems(), this function parse the different
**				combination and stock him in tab->combin[x].
**				COMBIN[4] :
**						combin[0] = `-`
**						combin[1] = `0`
**						combin[2] = `*`
**				combin[3] (`.`) is parse in parse_precisions()
**
**			@param t_tab *tab
**			@return tab
**
**	NOTE - Check MACRO COMBINE
*/

t_tab	*parse_combin(t_tab *tab)
{
	int i;

	i = 0;
	while (COMBINE[i] != '\0')
	{
		while (COMBINE[i] == tab->s_parse[tab->i])
		{
			while (tab->s_parse[tab->i] == '-' && tab->i++)
				tab->combin[0] = '-';
			while (tab->s_parse[tab->i] == '0' && tab->i++)
				tab->combin[1] = '0';
			while (tab->s_parse[tab->i] == '*' && tab->i++)
				tab->combin[2] = '*';
			i = 0;
		}
		i++;
	}
	return (tab);
}

/*
**	parse_width() :
**				Call secondly by get_elems(), this function parse the width
**				and stock him in tab->width.
**
**			@param t_tab *tab
**			@return tab
*/

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

/*
**	parse_precisions() :
**				Call thirdly by get_elems(), this function parse the precisions
**				and stock him in tab->precisions.
**				This is where tab->combin[3] is parse.
**					combin[3] = `.`
**
**			@param t_tab *tab
**			@return tab
*/

t_tab	*parse_precisions(t_tab *tab)
{
	while (tab->s_parse[tab->i] == '.' && tab->i++)
	{
		tab->precisions = 1;
		tab->combin[3] = '.';
	}
	if (ft_isdigit(tab->s_parse[tab->i]) == 1 && tab->combin[3] == '.')
	{
		tab->precisions = 0;
		tab->prec_null = 0;
	}
	while (ft_isdigit(tab->s_parse[tab->i]) == 1)
		tab->precisions = tab->precisions * 10 + (tab->s_parse[tab->i++] - 48);
	if (tab->s_parse[tab->i] == '*')
	{
		tab->precisions = va_arg(tab->args, int);
		if (tab->precisions < 0)
		{
			tab->prec_is_neg = TRUE;
			tab->precisions = -tab->precisions;
		}
		tab->i++;
	}
	return (tab);
}

/*
**	parse_flags() :
**				Call fourth by get_elems(), this function parse the flag
**				and stock him in tab->flag.
**
**			@param t_tab *tab
**			@return tab
**
**	NOTE - Check MACRO FLAGS
*/

t_tab	*parse_flags(t_tab *tab)
{
	size_t i;

	i = 0;
	while (FLAGS[i] == tab->s_parse[tab->i])
		i++;
	i = 0;
	while (FLAGS[i] != '\0')
	{
		if (FLAGS[i] == tab->s_parse[tab->i])
		{
			tab->flag = FLAGS[i];
			break ;
		}
		i++;
	}
	return (tab);
}
