/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 20:43:16 by thezerbibi        #+#    #+#             */
/*   Updated: 2020/04/19 03:47:47 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

int	get_width(intmax_t nbr)
{
		int width;

	width = 1;
	while ((nbr /= 10) > 0)
		width++;
	return (width);
}
