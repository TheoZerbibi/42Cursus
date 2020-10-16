/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/16 15:59:52 by thzeribi         ###   ########.fr       */
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
** -------------------------------------------------------------------
** 							COMBIN[4] :
** -------------------------------------------------------------------
**		.- combin[0] = '-'
**		.- combin[1] = '0'
**		.- combin[2] = '*'
**		.- combin[3] = '.'
** -------------------------------------------------------------------
**					GLOBAL_NOTE - Check MACRO COMBINE
** -------------------------------------------------------------------
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
	int			prec_is_neg;
	int			prec_null;
	int			nbr_is_neg;
	int			space_after;
	long	int	char_display;
	int			nbr_len;

}				t_tab;

/*
** -------------------------------------------------------------------
**								MAIN FUNCTION
** -------------------------------------------------------------------
**	ft_printf() :
**			Main function for PrintF
**
**		@param char *str & va_arg
**		@return tab.len
**
** -------------------------------------------------------------------
*/

int				ft_printf(const char *str, ...);
int				ft_parser(t_tab *tab);

/*
** -------------------------------------------------------------------
**							PARSING FUNCTION
** -------------------------------------------------------------------
**	parse_combin() :
**				Parse combination function.
**
**			@param t_tab *tab
**			@return tab
**
**	NOTE - Check MACRO COMBINE
**
** -------------------------------------------------------------------
**	parse_width() :
**				Parse width function.
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	parse_precisions() :
**				Parse precisions function.
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	parse_flags() :
**				Parse flags.
**
**			@param t_tab *tab
**			@return tab
**
**	NOTE - Check MACRO FLAGS
**
** -------------------------------------------------------------------
*/

t_tab			*parse_combin(t_tab *tab);
t_tab			*parse_width(t_tab *tab);
t_tab			*parse_precisions(t_tab *tab);
t_tab			*parse_flags(t_tab *tab);

/*
** -------------------------------------------------------------------
**							PRINT FUNCTION
** -------------------------------------------------------------------
**	print_c() :
**				This threat `c` and `%` flag
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	print_s() :
**				This threat `s` flag
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	print_d() :
**				This threat `d` and `i` flag
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	print_x() :
**				This threat `x` and `X` flag
**
**			@param t_tab *tab, int upper [BOOLEAN]
**				int upper :
**					[FALSE](0)	- the result will be lowercase [x]
**					[TRUE](1)		- the result will be uppercase [X]
**			@return tab
**
** -------------------------------------------------------------------
**	print_p() :
**				This threat `p` flag
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**	print_u() :
**				This threat `u` flag
**
**			@param t_tab *tab
**			@return tab
**
** -------------------------------------------------------------------
**					GLOBAL_NOTE - Check MACRO FLAGS
** -------------------------------------------------------------------
*/

t_tab			*print_c(t_tab *tab);
t_tab			*print_s(t_tab *tab);
t_tab			*print_d(t_tab *tab);
t_tab			*print_x(t_tab *tab, int upper);
t_tab			*print_p(t_tab *tab);
t_tab			*print_u(t_tab *tab);

/*
** -------------------------------------------------------------------
**							UTILS FUNCTION
** -------------------------------------------------------------------
**	display() :
**				General function for display.
**
**			@param t_tab *tab & int c & int len, int update_len [BOOLEAN]
**				int update_len :
**					[FALSE](0)	int len ​​will not be added to tab->len
**					[TRUE](1)		int len ​​will be added to tab->len
**			@return tab
** -------------------------------------------------------------------
*/

void			display(t_tab *tab, int c, int len, int update_len);

/*
** -------------------------------------------------------------------
**							OTHER FUNCTION
** -------------------------------------------------------------------
*/

t_tab			*d_utils_minus(t_tab *tab, int blank,
				char neg_char, int already_neg);
void			d_utils_minus_print(t_tab *tab, long int nbr,
				int width, int blank);
void			d_utils_positive_print(t_tab *tab, long int nbr,
				int width, int blank);

void			u_utils_positive(t_tab *tab, int width, int blank);
void			u_utils_positive_print(t_tab *tab, long int nbr,
					int width, int blank);

#endif
