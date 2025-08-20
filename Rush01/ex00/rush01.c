/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:49:14 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 19:44:20 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		validate(int field[4][4], int input[4][4]);
void	read_input(int input[4][4], char *argv[]);
int		vailidate_input(char argc, char *argv[]);
int		solve(int field[4][4], int position_x, int position_y, int input[4][4]);
// check input and execute code

int	main(int argc, char *argv[])
{
	int		input[4][4];
	int		field[4][4];

	if (!vailidate_input(argc, argv))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	read_input(input, argv);
	if (!solve(field, 0, 0, input))
		write(1, "ERROR\n", 6);
	return (0);
}

// check if argcount = 2, if input contains nmbr 1 - 4, and if 16 
//char with spaces
int	vailidate_input(char argc, char *argv[])
{
	int		index;

	if (argc != 2)
		return (0);
	index = 0;
	while (argv[1][index] != '\0')
	{
		if (index % 2 == 0)
		{
			if (argv[1][index] < '1' || argv[1][index] > '4')
				return (0);
		}
		else
		{
			if (argv[1][index] != ' ')
				return (0);
		}
		index++;
	}
	if (index != 31)
		return (0);
	return (1);
}

// read input and map to the field
void	read_input(int input[4][4], char *argv[])
{
	int	index;

	index = 0;
	while (index < 16)
	{
		input[(int)(index / 4)][index % 4] = (argv[1][2 * index] - 48);
		index++;
	}
}
