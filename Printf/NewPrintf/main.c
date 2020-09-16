/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:34:47 by thzeribi          #+#    #+#             */
/*   Updated: 2020/09/16 04:07:46 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

#define SUCCESS "\033[1;32m✓\033[0m"
#define FAIL "\033[1;31mx\033[0m"
#define HEXA 60
#define STR NULL
int GLOBAL_ERR = 0;
int GLOBAL_TEST = 0;

void	calc_test(int nbr)
{
	GLOBAL_TEST += nbr;
}

void success(void)
{
	printf("\033[1;32mOK   %24s\n", "✓\033[0m");
}

void fail(char *reason)
{
	GLOBAL_ERR += 1;
	if (reason == NULL || reason[0] == '\0')
		reason = "undefined";
	int size = ft_strlen(reason) + 1;
	int indent = 15;
	if (size > 14)
		indent -= 14;
	else
		indent -= size -1;
	printf("\033[1;31mFail : %5.14s %*s\033[0m\n", reason, indent, "x");
}

int	main(void)
{
	//char p = 10;

	printf("\n\n\n|-------PRINTF-MAIN-BREAKER-------|\n\n");

	/*printf("\n-------%s POINTER %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(2);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*p|)", -20, &p));
	printf(" = vrai = [%d]\n", printf("(|%*p|)", -20, &p));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%p|)", NULL));
	printf(" = vrai = [%d]\n", printf("(|%p|)", NULL));
	success();

	printf("\n-------%s INT NEGATIF %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(14);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", -10));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", -10));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", -10));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", -10));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",10, -4, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", 10, -4, -10));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, -10));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", -10));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -4, -12));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", 7, -12));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*d|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*d|)", 7, -12));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04d|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04d|)", -10));
	success();
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", -2147483648));
	printf(" = vrai = [%d]\n", printf("(|%ld|)", -2147483648));
	success();
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%4d|)", -12));
	printf(" = vrai = [%d]\n", printf("(|%4d|)", -12));
	success();
	printf("-------TEST 14-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%-.0d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%-.0d|)", 0));
	success();

	printf("\n-------%s INT POSITIF %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(12);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 10));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 10));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 10));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 10));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 10));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 10));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 10));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 10));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 2147483647));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 2147483647));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%3.0d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%3.0d|)", 0));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%---.*d|)", 5, 0));
	printf(" = vrai = [%d]\n", printf("(|%---.*d|)", 5, 0));
	success();

	printf("\n-------%s INT ZERO %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(10);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.d|)", 0));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.d|)", 0));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2d|)", 0));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00d|)", 0));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -10, 3, 0));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*d|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*d|)", -5, 8, 0));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*d|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*d|)", -10, 0));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%d|)", 0));
	success();
	printf("-------TEST 10------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%1d|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%1d|)", 0));

	printf("\n-------%s CHAR %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(5);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10c|)", '\0'));
	printf(" = vrai = [%d]\n", printf("(|%10c|)", '\0'));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*%|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%0*%|)", 10));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", 10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", 10, 'j'));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*c|)", -10, 'j'));
	printf(" = vrai = [%d]\n", printf("(|%*c|)", -10, 'j'));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%c|)", '5'));
	printf(" = vrai = [%d]\n", printf("(|%c|)", '5'));
	success();*/

	printf("\n-------%s STRING %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(14);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%10.s|)", STR));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%s|)", STR));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10.2s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%10.2s|)", STR));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", -5, -10, STR));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)",-5, -10, STR));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-10, 3, STR));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -10, 3, STR));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)",-5, 8, STR));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", -5, 8, STR));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*s|)", 9, 12, STR));
	printf(" = vrai = [%d]\n", printf("(|%*.*s|)", 9, 12, STR));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", printf("(|%*s|)", -10, STR));
	printf(" = vrai = [%d]\n", printf("(|%*s|)", -10, STR));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%s|)", STR));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%-2s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%-2s|)", STR));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.2s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%.2s|)", STR));
	success();
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%--2s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%---2s|)", STR));
	success();
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.0s|)", STR));
	printf(" = vrai = [%d]\n", printf("(|%.0s|)", STR));
	success();
	printf("-------TEST 14-------\n");
	printf(" = mien = [%d]\n", ft_printf("(| %s %-10.5s|)", "oui", "non"));
	printf(" = vrai = [%d]\n", printf("(| %s %-10.5s|)", "oui", "non"));
	success();

	/*printf("\n-------%s HEXA %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(16);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%x|)", HEXA));
	printf(" = vrai = [%d]\n", printf("(|%x|)", HEXA));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%10x|)", HEXA));
	printf(" = vrai = [%d]\n", printf("(|%10x|)", HEXA));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*x|)", 8, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*x|)", 8, HEXA));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.x|)", 8, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.x|)", 8, HEXA));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.5x|)", 8, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.5x|)", 8, HEXA));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", 8, 3, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", 8, 3, HEXA));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, 3, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, 3, HEXA));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, HEXA));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%*.*x|)", -5, -3, -HEXA));
	printf(" = vrai = [%d]\n", printf("(|%*.*x|)", -5, -3, -HEXA));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -10, 8, -HEXA));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -10, 8, -HEXA));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05x|)", HEXA));
	printf(" = vrai = [%d]\n", printf("(|%05x|)", HEXA));
	success();
	printf("-------TEST 12-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05.10x|)", HEXA));
	printf(" = vrai = [%d]\n", printf("(|%05.10x|)", HEXA));
	success();
	printf("-------TEST 13-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, 5, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, 5,  HEXA));
	success();
	printf("-------TEST 14-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, HEXA));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, HEXA));
	success();
	printf("-------TEST 15-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*x|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%.*x|)", -10, 0));
	success();
	printf("-------TEST 16-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*x|)", -3, -5, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*x|)", -3, -5, 0));
	success();

	printf("\n-------%s UNSIGNED POSITIFS %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(11);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 10));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 10));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 10));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 10));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, -5, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, -5, 10));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 10));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 10));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 10));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",5, 8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 5, 8, 10));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",5, -8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 5, -8, 10));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",6, -8, 10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 6, -8, 10));
	success();

	printf("\n-------%s UNSIGNED NEGATIFS %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(11);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", -10));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", -10));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", -10));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", -10));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",20, -14, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", 20, -14, -10));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-18, 8, -10));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -18, 8, -10));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%u|)", -10));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -4, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -4, -12));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", 7, -12));
	success();
	printf("-------TEST 10-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.*u|)", 7, -12));
	printf(" = vrai = [%d]\n", printf("(|%.*u|)", 7, -12));
	success();
	printf("-------TEST 11-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%04u|)", -10));
	printf(" = vrai = [%d]\n", printf("(|%04u|)", -10));
	success();

	printf("\n-------%s UNSIGNED ZERO %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(9);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.u|)", 0));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00.u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00.u|)", 0));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%010.2u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%010.2u|)", 0));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%00u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%00u|)", 0));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-10, 3, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -10, 3, 0));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*.*u|)",-5, 8, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*.*u|)", -5, 8, 0));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0*u|)", -10, 0));
	printf(" = vrai = [%d]\n", printf("(|%0*u|)", -10, 0));
	success();
	printf("-------TEST 9-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%u|)", 0));
	printf(" = vrai = [%d]\n", printf("(|%u|)", 0));
	success();

	printf("\n-------%s CAS SPECIFIC %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(5);
	printf("-------TEST 1-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%%|)"));
	printf(" = vrai = [%d]\n", printf("(|%%|)"));
	success();
	printf("-------TEST 2-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%5%|)"));
	printf(" = vrai = [%d]\n", printf("(|%5%|)"));
	success();
	printf("-------TEST 3-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%-5%|)"));
	printf(" = vrai = [%d]\n", printf("(|%-5%|)"));
	success();
	printf("-------TEST 4-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%05.%|)"));
	printf(" = vrai = [%d]\n", printf("(|%05.%|)"));
	success();
	printf("-------TEST 5-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%0-5.%|)"));
	printf(" = vrai = [%d]\n", printf("(|%0-5.%|)"));
	success();
	printf("-------TEST 6-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|%%%%%d|)", 10));
	printf(" = vrai = [%d]\n", printf("(|%%%%%d|)", 10));
	success();
	printf("-------TEST 7-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|bonjour %*.2s %%%d|)", 0, "bonjour", 10));
	printf(" = vrai = [%d]\n", printf("(|bonjour %*.2s %%%d|)", 0, "bonjour", 10));
	success();
	printf("-------TEST 8-------\n");
	printf(" = mien = [%d]\n", ft_printf("(|bonjour %Xxd|)", 42));
	printf(" = vrai = [%d]\n", printf("(|bonjour %Xxd|)", 42));
	success();*/

	/*printf("\n-------%s LEAKS %s-------\n\n", SUCCESS, SUCCESS);
	calc_test(1);
	system("leaks printf");
	success();*/

	ft_putstr("\n============================================= DEBUGGER =============================================\n");
	printf(" = mien = [%d]\n", ft_printf("(|%.s|)", "coco"));
	printf(" = vrai = [%d]\n", printf("(|%.s|)", "coco"));
	success();
	//u%4.2ss %-1.s\n %---5.3s , "coco", NULL, "yooo"
	ft_putstr("====================================================================================================\n");
	printf("\n\n\033[1;32mScore : %d/%d\033[0m\n\033[1;33mBugs  : %d\033[0m\n", (GLOBAL_TEST - GLOBAL_ERR), GLOBAL_TEST, GLOBAL_ERR);
	return (0);
}
