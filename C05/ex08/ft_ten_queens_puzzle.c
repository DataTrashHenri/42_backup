/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:07:08 by hrock             #+#    #+#             */
/*   Updated: 2025/08/19 15:05:26 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check_diagonals(int field[10][10], int x, int y, int diagonal )
{
	diagonal = -1;
	while ((x + diagonal) >= 0 && (y + diagonal) >= 0)
	{
		if (field[x + diagonal][y + diagonal] == 1)
			return (0);
		diagonal--;
	}
	diagonal = 1;
	while ((x + diagonal) < 10 && (y - diagonal) >= 0)
	{	
		if (field[x + diagonal][y - diagonal] == 1)
			return (0);
		diagonal++;
	}
	diagonal = -1;
	while ((x + diagonal) >= 0 && (y - diagonal) < 10)
	{
		if (field[x + diagonal][y - diagonal] == 1)
			return (0);
		diagonal--;
	}
	return (1);
}

int	queen_can_move(int field[10][10], int x, int y)
{
	int		down_index;
	int		diagonal;

	down_index = 0;
	while (down_index < 10)
	{
		if (field[x][down_index] == 1)
			return (0);
		down_index++;
	}
	diagonal = 1;
	while ((x + diagonal) < 10 && (y + diagonal) < 10)
	{
		if (field[x + diagonal][y + diagonal] == 1)
			return (0);
		diagonal++;
	}
	if (!check_diagonals(field, x, y, diagonal))
		return (0);
	return (1);
}

void	convert_field_output(int field[10][10])
{
	int			row;
	int			index;
	char		c;

	row = 0;
	while (row < 10)
	{
		index = 0;
		while (index < 10)
		{
			if (field[index][row] == 1)
			{
				c = (index + 48);
				write(1, &c, 1);
			}
			index++;
		}
		row++;
	}
	write(1, "\n", 1);
}

void	try_queen(int field[10][10], int row)
{
	int		column;

	column = 0;
	while (column < 10)
	{
		if (queen_can_move(field, column, row) == 1)
		{
			field[column][row] = 1;
			if (row == 9)
			{
				convert_field_output(field);
				field[column][row] = 0;
				return ;
			}
			try_queen(field, row + 1);
			field[column][row] = 0;
		}
		column++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	field[10][10];
	int	column;
	int	row;

	column = 0;
	while (column < 10)
	{
		row = 0;
		while (row < 10)
		{
			field[column][row] = 0;
			row++;
		}
		column++;
	}
	try_queen(field, 0);
	return (724);
}
