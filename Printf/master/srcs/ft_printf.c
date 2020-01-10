/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:19 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/10 01:25:18 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
**	functions : ft_params
**	description :
*/

static int	ft_init(t_tab *opt)
{
	tab->len = 0;
}

/*
**	functions : ft_printf
**	description :
*/

int			ft_printf(const char *str, ...)
{
	t_tab	*opt;

	if (!(opt = (t_tab*)malloc(sizeof(t_tab))))
		return (ERROR);
	opt->str = str;

	return (0);
}
