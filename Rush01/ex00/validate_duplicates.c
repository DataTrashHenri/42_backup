/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:52:49 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 20:11:12 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compare every index with every other index in the Array
int	has_duplicates(int array[4])
{
	int	index;
	int	inner_index;

	index = 0;
	while (index < 3)
	{
		inner_index = index + 1;
		while (inner_index < 4)
		{
			if (array[index] == array[inner_index])
				return (1);
			inner_index++;
		}
		index++;
	}
	return (0);
}

// check duplicates vertical column by column
int	check_vertical(int field[4][4], int row, int column, int current_array[4])
{
	column = 0;
	while (column < 4)
	{
		row = 0;
		while (row < 4)
		{
			current_array[row] = field[column][row];
			row++;
		}
		if (has_duplicates(current_array))
			return (0);
		column++;
	}
	return (1);
}

// check duplicates horizontal row by row
int	check_duplicates(int field[4][4])
{
	int	row;
	int	column;
	int	current_array[4];

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			current_array[column] = field[column][row];
			column++;
		}
		if (has_duplicates(current_array))
			return (0);
		row ++;
	}
	return (check_vertical(field, row, column, current_array));
}
