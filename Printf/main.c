/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:00:53 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/05 22:29:13 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./master/includes/ft_printf.h"

void succes(void)
{
	printf("\033[1;32m");
	printf("OK   %25s\n", "✓");
	printf("\033[0m");
}

void fail(char *reason)
{
	if (reason[0] == '\0')
		reason = "null";
	int size = ft_strlen(reason) + 1;
	int indent = 20;
	if (size >= 10)
		indent -= 10;
	else
		indent -= size - 1;
	printf("\033[1;31m");
	printf("Fail : %5.10s %*s\n", reason, indent, "x");
	printf("\033[0m");
}

int	main(void)
{
	//int hexa = 60;
	//char a = 10;
	//char *str = NULL;


	printf("\n\n\n|-------PRINTF-MAIN-BREAKER-------|\n\n");
	/*printf("\n-------\033[1;32m✓\033[0m POINTER\033 [1;32m✓\033[0m-------\n\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*p|)", -20, &a));
	printf(" = vrai = [%d]\n", printf("(|%*p|)", -20, &a));
	succes();
*/
	printf("\n\n\n-------\033[1;32m✓\033[0m INT NEGATIFS \033[1;32m✓\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", -10));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", -10));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", -10));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", -10));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",10, -4, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", 10, -4, -10));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, -10));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", -10));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -4, -12));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", 7, -12));
	succes();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*d|)", 7, -12));
	succes();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04d|)", -10));
	succes();
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", -2147483648));
	printf(" = vrai = [%d]\n", printf("(|%ld|)", -2147483648));
	succes();
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%4d|)", -12));
	printf(" = vrai = [%d]\n", printf("(|%4d|)", -12));
	fail("All");


	printf("\n\n\n-------\033[1;32m✓\033[0m INT POSITIFS \033[1;32m✓\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 10));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 10));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 10));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 10));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 10));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 10));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 10));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 10));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 2147483647));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 2147483647));
	succes();

	printf("\n\n\n-----------\033[1;32m✓\033[0m INT ZERO \033[1;32m✓\033[0m-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 0));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 0));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 0));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 0));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 0));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 0));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 0));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	succes();
//	printf("-------TEST 10------\n");
//	printf(" = mien = [%d]\n", ft_printf("(|%1d|)"));
//	printf(" = vrai = [%d]\n", printf("(|%1d|)"));

/*
	printf("\n\n\n-----------\033[1;32m✓\033[0m CHAR \033[1;32m✓\033[0m-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10c|)", '\0'));
	printf(" = vrai = [%d]\n", printf("(|%10c|)", '\0'));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*%|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%0*%|)", 10));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", 10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", 10, 'j'));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", -10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", -10, 'j'));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%c|)", '5'));
	printf(" = vrai = [%d]\n", printf("(|%c|)", '5'));
	succes();

	printf("\n\n\n-------\033[1;32m✓\033[0m STRING \033[1;32m✓\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%10.s|)", str));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%s|)", str));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.2s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%10.2s|)", str));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", -5, -10, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)",-5, -10, str));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-10, 3, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -10, 3, str));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-5, 8, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -5, 8, str));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", 9, 12, str));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", 9, 12, str));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", printf("(|%*s|)", -10, str));
	printf(" = vrai = [%d]\n", printf("(|%*s|)", -10, str));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", str));
	printf(" = vrai = [%d]\n", printf("(|%s|)", str));
	succes();

	printf("\n\n\n-------\033[1;31mx\033[0m HEXA \033[1;31mx\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%x|)", hexa));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%10x|)", hexa));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*x|)", 8, hexa));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.x|)", 8, hexa));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.5x|)", 8, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.5x|)", 8, hexa));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", 8, 3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", 8, 3, hexa));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, 3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, 3, hexa));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, hexa));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, -hexa));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, -hexa));
	fail("Bad size");
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -10, 8, -hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -10, 8, -hexa));
	fail("Bad indentation");
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%05x|)", hexa));
	fail("Bad indentation");
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05.10x|)", hexa));
	printf(" = vrai = [%d]\n", printf("(|%05.10x|)", hexa));
	fail("Bad indentation");
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, 5, hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, 5,  hexa));
	fail("Bad size");
	printf("-------TEST 14-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, hexa));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, hexa));
	succes();
	printf("-------TEST 15-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*x|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%.*x|)", -10, 0));
	fail("Bad size");
	printf("-------TEST 16-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, 0));
	succes();
*/

	printf("\n\n\n-------\033[1;31mx\033[0m UNSIGNED POSITIVE \033[1;31mx\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 10));
	fail("Bad indentation");
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 10));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 10));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 10));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, -5, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, -5, 10));
	fail("Bad indentation");
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 10));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 10));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 10));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 5, 8, 10));
	succes();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",5, -8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 5, -8, 10));
	fail("Bad indentation");
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",6, -8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 6, -8, 10));
	fail("Bad indentation");

	printf("\n\n\n-------\033[1;31mx\033[0m UNSIGNED NEGATIFS \033[1;31mx\033[0m-------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", -10));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", -10));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", -10));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", -10));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",20, -14, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 20, -14, -10));
	fail("Bad indentation");
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-18, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -18, 8, -10));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", -10));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -4, -12));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", 7, -12));
	succes();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*u|)", 7, -12));
	succes();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04u|)", -10));
	succes();

/*
	printf("\n\n\n-----------\033[1;32m✓\033[0m UNSIGNED ZERO \033[1;32m✓\033[0m-----------\n\n");
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 0));
	succes();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 0));
	succes();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 0));
	succes();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 0));
	succes();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, 3, 0));
	succes();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 0));
	succes();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));
	succes();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 0));
	succes();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));
	succes();
*/

//	printf("%%\n");
//	ft_printf("%%\n");
//	succes();

//	system("leaks printf");
	return (0);
}
