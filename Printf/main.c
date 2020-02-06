/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:00:53 by thzeribi          #+#    #+#             */
/*   Updated: 2020/02/03 07:06:34 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./master/includes/ft_printf.h"

int	main(void)
{
	//ft_printf("Hello World %.c %d!\n", 10, 10);
	//ft_printf("Hello %s !\n", "World");
	char *str = NULL;
	printf("\n\n\n-------STRING-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%10.s|)", str));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%s|)", str));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.2s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%10.2s|)", str));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", -5, -10, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)",-5, -10, str));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-10, 3, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -10, 3, str));
	printf("-------TEST -------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-5, 8, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -5, 8, str));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", 9, 12, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", 9, 12, str));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", printf("(|%*s|)", -10, str));
	printf(" = vrai = [%d]\n", printf("(|%*s|)", -10, str));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%s|)", str));

	system("leaks test");


	return (0);
}
