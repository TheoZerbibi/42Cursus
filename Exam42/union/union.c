/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:46:21 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/20 19:27:25 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	int i;
	int y;
	int tmp;
	int check;
	int tmp2;

	i = 0;
	y = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		tmp = 0;
		check = 0;
		while (tmp < i)
		{
			if (argv[1][i] == argv[1][tmp])
			{
				check = 1;
				break;
			}
			tmp++;
		}
		if (!check)
			write(1, &argv[1][i], 1);
		i++;
	}
	while (argv[2][y])
	{
		tmp = 0;
		check = 0;
		while (tmp < y)
		{
			tmp2 = 0;
			while (argv[1][tmp2])
			{
				if (argv[2][y] == argv[1][tmp2])
				{
					check = 1;
					break;
				}
				tmp2++;
			}
			if (argv[2][y] == argv[2][tmp])
			{
				check = 1;
				break;
			}
			tmp++;
		}
		if (!check)
			write(1, &argv[2][y], 1);
		y++;
	}
	write(1, "\n", 1);
	return (0);
}
