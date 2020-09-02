/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:00:53 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/02 21:38:49 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./master/includes/ft_printf.h"

int	main(void)
{
	int hexa = 60;
	//char a = 10;
	//char *str = NULL;

	//printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 10));
	//printf(" = vrai = [%d]\n", printf("(|%010.u|)", 10));

	//printf(" = mien = [%d]\n", ft_printf("(|%*p|)", -20, &a));
	//printf(" = vrai = [%d]\n", printf("(|%*p|)", -20, &a));


	/*printf("-------INT NEGATIFS-------\n\n");
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


	printf("\n\n\n-------INT POSITIFS-------\n\n");
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

	printf("\n\n\n-----------INT ZERO-----------\n\n");
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
//	printf("-------TEST 10------\n");
//	printf(" = mien = [%d]\n", ft_printf("(|%1d|)"));
//	printf(" = vrai = [%d]\n", printf("(|%1d|)"));

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
	printf(" = vrai = [%d]\n", printf("(|%s|)", str));*/

	printf("\n\n\n-------HEXA-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%x|)", hexa));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%10x|)", hexa));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*x|)", 8, hexa));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.x|)", 8, hexa));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.5x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.5x|)", 8, hexa));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", 8, 3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", 8, 3, hexa));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, 3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, 3, hexa));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, hexa));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, -hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, -hexa));
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -10, 8, -hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -10, 8, -hexa));
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%05x|)", hexa));
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05.10x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%05.10x|)", hexa));
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, 5, hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, 5,  hexa));
	printf("-------TEST 14-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, hexa));
	printf("-------TEST 15-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*x|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%.*x|)", -10, 0));
	printf("-------TEST 16-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, 0));

	/*printf("\n\n\n-------UNSIGNED POSITIVE-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 10));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 10));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 10));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 10));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, 3, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, 3, 10));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 10));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 10));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 10));


	printf("\n\n\n-------UNSIGNED NEGATIFS-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", -10));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", -10));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", -10));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", -10));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",20, -14, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 20, -14, -10));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-18, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -18, 8, -10));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", -10));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -4, -12));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", 7, -12));
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*u|)", 7, -12));
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04u|)", -10));

	printf("\n\n\n-----------UNSIGNED ZERO-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 0));
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 0));
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 0));
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 0));
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, 3, 0));
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 0));
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 0));
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));*/

	//printf("%%\n");
	//ft_printf("%%\n");

	//system("leaks printf");

	return (0);
}
