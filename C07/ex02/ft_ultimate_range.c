/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:09:18 by hrock             #+#    #+#             */
/*   Updated: 2025/08/16 09:10:31 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	get_size(int *arr)
{
	int	index;

	index = 0;
	while (arr[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	index = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (range == NULL)
	{
		return (-1);
	}
	range[0] = malloc(sizeof(int) * (max - min));
	while (index + min < max)
	{
		range[0][index] = index + min;
		index++;
	}
	return (max - min);
}
