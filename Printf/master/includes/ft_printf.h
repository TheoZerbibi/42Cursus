/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/04 20:23:40 by thzeribi         ###   ########.fr       */
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
# define CONVERT "cspdiuxX%"
# define COMBINE "-0*"
# define BASE "0123456789abcdef"

/*
** Subject : Combin[3]
** Combin[0] = '-'
** Combin[1] = '0'
** Combin[2] = '*'
** Combin[3] = '.'
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
	char		flags;
	char		arg_flag;
	char		combin[4];
	int			width_is_neg;
	int			prec_neg;
	int			param;

}				t_tab;

int				ft_printf(const char *str, ...);
int				ft_parser(t_tab *tab);
int				get_elems(t_tab *tab);
int				get_width(long int nbr);
t_tab			*init_printf(t_tab *tab);
t_tab			*parse_combin(t_tab *tab);
t_tab			*parse_precisions(t_tab *tab);
t_tab			*parse_width(t_tab *tab);
t_tab			*parse_convert(t_tab *tab);
t_tab			*parse_elems(t_tab *tab);
t_tab			*print_c(t_tab *tab);
t_tab			*print_s(t_tab *tab);
t_tab			*print_d(t_tab *tab);
t_tab			*print_x(t_tab *tab, int upper);
t_tab			*print_p(t_tab *tab);
t_tab			*display_d(t_tab *tab, long int num, int num_width,
				int align_left);
t_tab			*display_p(t_tab *tab, char *str, int indent);
t_tab			*print_u(t_tab *tab);
void			display(t_tab *tab, int c, int len, int len2);
void			display_c(t_tab *tab, char c);
void			print_minus(t_tab *tab, long int nbr, int width, int is_neg);
void			print_positive(t_tab *tab, long int nbr, int width);

#endif
