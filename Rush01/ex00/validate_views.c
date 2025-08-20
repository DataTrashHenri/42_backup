/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:11:58 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 20:17:54 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks each row or column at position, going through and checks ,
//how often we gets a new highest box size 
// view 0 -> checks from the top view, x = const. and y = index++
int	validate_view_top(int position, int field[4][4], int v_array[4])
{
	int		index;
	int		visible_boxes;
	int		highest;

	index = 0;
	visible_boxes = 1;
	highest = field[position][index];
	while (index < 4)
	{
		if (field[position][index] > highest)
		{
			visible_boxes++;
			highest = field[position][index];
		}
		index++;
	}
	if (visible_boxes == v_array[position])
		return (1);
	return (0);
}

// view 1 -> checks from the bottom view, x = const. and y = index--
int	validate_view_bottom(int position, int field[4][4], int v_array[4])
{
	int		index;
	int		visible_boxes;
	int		highest;

	index = 3;
	visible_boxes = 1;
	highest = field[position][index];
	while (index >= 0)
	{
		if (field[position][index] > highest)
		{
			visible_boxes++;
			highest = field[position][index];
		}
		index--;
	}
	if (visible_boxes == v_array[position])
		return (1);
	return (0);
}

// view 2 -> checks from the left view, x = index++ and y = const.
int	validate_view_left(int position, int field[4][4], int v_array[4])
{
	int		index;
	int		visible_boxes;
	int		highest;

	index = 0;
	visible_boxes = 1;
	highest = field[index][position];
	while (index < 4)
	{
		if (field[index][position] > highest)
		{
			visible_boxes++;
			highest = field[index][position];
		}
		index++;
	}
	if (visible_boxes == v_array[position])
		return (1);
	return (0);
}

// view 3 -> checks from the right view, x = index-- and y = const.
int	validate_view_right(int position, int field[4][4], int v_array[4])
{
	int		index;
	int		visible_boxes;
	int		highest;

	index = 3;
	visible_boxes = 1;
	highest = field[index][position];
	while (index >= 0)
	{
		if (field[index][position] > highest)
		{
			visible_boxes++;
			highest = field[index][position];
		}
		index--;
	}
	if (visible_boxes == v_array[position])
		return (1);
	return (0);
}
