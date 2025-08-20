/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:41:09 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 23:59:24 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	validate(int field[4][4], int input[4][4]);
// print the current if "solve funciton" found solution then return(1) to solve

int	validate_and_print(int field[4][4], int input[4][4])
{
	int		index_x;
	int		index_y;
	char	current_char;

	if (validate(field, input))
	{
		index_y = 0;
		while (index_y < 4)
		{
			index_x = 0;
			while (index_x < 4)
			{
				current_char = field[index_x][index_y] + 48;
				write(1, &current_char, 1);
				if (index_x != 3)
					write(1, " ", 1);
				index_x++;
			}
			write(1, "\n", 1);
			index_y++;
		}
		return (1);
	}
	return (0);
}

// solution finder, calles it self recursively, x = y = 3 ->
//check if solution was found 
int	solve(int field[4][4], int position_x, int position_y, int input[4][4])
{
	int	height;

	height = 1;
	while (height <= 4)
	{
		field[position_x][position_y] = height;
		if (position_x == 3 && position_y == 3)
		{
			if (validate_and_print(field, input))
				return (1);
		}
		else if (position_x == 3)
		{
			if (solve(field, 0, position_y + 1, input))
				return (1);
		}
		else
		{
			if (solve(field, position_x + 1, position_y, input))
				return (1);
		}
		height++;
	}
	return (0);
}
