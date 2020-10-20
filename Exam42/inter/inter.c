/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:17:24 by thzeribi          #+#    #+#             */
/*   Updated: 2020/10/20 15:45:12 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int y;
	int temp;
	int check;

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		y = 0;
		while (argv[2][y])
		{
			if (argv[1][i] == argv[2][y])
			{
				temp = 0;
				check = 0;
				while (i > temp)
				{
					if (argv[1][temp] == argv[1][i])
					{
						check = 1;
						break;
					}
					temp++;
				}
				if (check == 0)
					write(1, &argv[2][y], 1);
				break;
			}
			y++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
