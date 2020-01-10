/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:32:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/10 01:04:48 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR -1

typedef struct	s_tab
{
	const char	*str;
	int					len;
}				t_tab;

int			ft_printf(const char *str, ...);

#endif
