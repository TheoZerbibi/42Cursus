/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 01:09:06 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0
# define FLAGS "cspdiuxX%"
# define COMBINE "-0*"
# define BASE "0123456789abcdef"

/*
** COMBIN[4] :
**			combin[0] = '-'
**			combin[1] = '0'
**			combin[2] = '*'
**			combin[3] = '.'
*/

typedef struct	s_tab
{
	const char	*str;
	char		*s_copy;
	char		*s_parse;
	va_list		args;
	size_t		len;
	size_t		i;
	long int	width;
	long int	precisions;
	char		flag;
	char		combin[4];
	int			width_is_neg;
	int			prec_neg;
	int			nbr_is_neg;

}				t_tab;

/*
**	MAIN
**	ft_printf() :
**			Main function for PrintF
**			@param char *str & va_arg
**			@return tab.len
*/

int				ft_printf(const char *str, ...);
int				ft_parser(t_tab tab);

/*
**	PARSING
**	parse_combin() :
**				Parse combination function.
**				@param t_tab tab
**				@return tab
**				NOTE - Check MACRO COMBINE
** -------------------------------------------------------------------
**	parse_width() :
**				Parse width function.
**				@param t_tab tab
**				@return tab
** -------------------------------------------------------------------
**	parse_precisions() :
**				Parse precisions function.
**				@param t_tab tab
**				@return tab
** -------------------------------------------------------------------
**	parse_flags() :
**				Parse flags.
**				@param t_tab tab
**				@return tab
**				NOTE - Check MACRO FLAGS
*/

t_tab			*parse_combin(t_tab *tab);
t_tab			*parse_width(t_tab *tab);
t_tab			*parse_precisions(t_tab *tab);
t_tab			*parse_flags(t_tab *tab);

t_tab			*print_c(t_tab *tab);
t_tab			*print_s(t_tab *tab);
t_tab			*print_d(t_tab *tab);
t_tab			*print_x(t_tab *tab, int upper);
t_tab			*print_p(t_tab *tab);

#endif
