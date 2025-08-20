/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:45:35 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 20:25:39 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_view(int view, int view_array[4], int field[4][4]);
int	validate_view_top(int position, int field[4][4], int v_array[4]);
int	validate_view_bottom(int position, int field[4][4], int v_array[4]);
int	validate_view_left(int position, int field[4][4], int v_array[4]);
int	validate_view_right(int position, int field[4][4], int v_array[4]);
int	validate_viewpoint(int view, int position, int field[4][4], int v_array[4]);
int	check_duplicates(int field[4][4]);

// first check duplicates, then creat current view array from input,
// then check every view
int	validate(int field[4][4], int input[4][4])
{
	int	view;
	int	view_array[4];
	int	index;

	view = 0;
	if (!check_duplicates(field))
		return (0);
	while (view < 4)
	{
		index = 0;
		while (index < 4)
		{
			view_array[index] = input[view][index];
			index++;
		}
		if (!validate_view(view, view_array, field))
			return (0);
		view++;
	}
	return (1);
}

// checkt eine view ab, z,b die von oben, ob dort alles passt
int	validate_view(int view, int view_array[4], int field[4][4])
{
	int	cell;

	cell = 0;
	while (cell < 4)
	{
		if (!validate_viewpoint(view, cell, field, view_array))
			return (0);
		cell++;
	}
	return (1);
}

// checkt viewpoint von irgend einer view ab, obs passt. 
int	validate_viewpoint(int view, int position, int field[4][4], int v_array[4])
{
	if (view == 0)
	{
		if (!validate_view_top(position, field, v_array))
			return (0);
		return (1);
	}
	if (view == 1)
	{
		if (!validate_view_bottom(position, field, v_array))
			return (0);
		return (1);
	}
	if (view == 2)
	{
		if (!validate_view_left(position, field, v_array))
			return (0);
		return (1);
	}
	if (view == 3)
	{
		if (!validate_view_right(position, field, v_array))
			return (0);
		return (1);
	}
	return (-99999);
}
