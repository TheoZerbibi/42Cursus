/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:00:53 by thzeribi          #+#    #+#             */
/*   Updated: 2020/05/11 08:29:30 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./master/includes/ft_printf.h"

int	main(void)
{
	/*printf("%c", 'a');
	ft_printf("%c", 'a');*/
	printf("-------NEGATIFS-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", -10));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", -10));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", -10));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", -10));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",10, -4, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", 10, -4, -10));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, -10));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", -10));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -4, -12));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", 7, -12));
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*d|)", 7, -12));
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04d|)", -10));


	/*printf("\n\n\n-------POSITIFS-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 10));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 10));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 10));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 10));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 10));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 10));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 10));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 10));

	printf("\n\n\n-----------ZERO-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 0));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 0));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 0));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 0));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 0));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 0));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 0));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	printf("-------TEST 10------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%1d|)"));

	printf("\n\n\n-----------CHAR-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10c|)", '\0'));
	printf(" = vrai = [%d]\n", printf("(|%10c|)", '\0'));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*%|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%0*%|)", 10));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", 10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", 10, 'j'));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", -10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", -10, 'j'));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%c|)", '5'));
	printf(" = vrai = [%d]\n", printf("(|%c|)", '5'));

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
	printf("-------TEST 6-------\n");
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

	printf("%%\n");
	ft_printf("%%\n");*/

	//system("leaks test");

	return (0);
}
