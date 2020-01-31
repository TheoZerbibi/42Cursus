/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:00:53 by thzeribi          #+#    #+#             */
/*   Updated: 2020/01/31 07:00:33 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./master/includes/ft_printf.h"

int	main(void)
{
	//ft_printf("Hello World %.c %d!\n", 10, 10);
	//ft_printf("Hello %s !\n", "slt");
	ft_printf("\t\t\t\t: |%-915s|\n", "Hello World!");
	return (0);
}
