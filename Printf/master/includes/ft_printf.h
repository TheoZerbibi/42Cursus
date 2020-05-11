/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/05/11 08:24:54 by thzeribi         ###   ########.fr       */
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
# define CONVERT "cspdiuxX%"
# define COMBINE "-0*"

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
	int			param;

}				t_tab;

int			ft_printf(const char *str, ...);
int			ft_parser(t_tab *tab);
int			get_elems(t_tab *tab);
int			get_width(long int nbr);
t_tab		*init_printf(t_tab *tab);
t_tab		*parse_combin(t_tab *tab);
t_tab		*parse_precisions(t_tab *tab);
t_tab		*parse_width(t_tab *tab);
t_tab		*parse_convert(t_tab *tab);
t_tab		*parse_elems(t_tab *tab);
t_tab		*print_c(t_tab *tab);
t_tab		*print_s(t_tab *tab);
t_tab		*print_d(t_tab *tab);
t_tab		*display_d(t_tab *tab, long int num, int num_width, int align_left);
void		display(t_tab *tab, int c, int len, int len2);
void		display_c(t_tab *tab, char c);

#endif
