/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:52:19 by hrock             #+#    #+#             */
/*   Updated: 2025/08/14 22:11:06 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	arr_size;
	int	*arr;
	int	index;

	if (min >= max)
	{
		return (0);
	}
	arr_size = max - min;
	arr = malloc(arr_size * sizeof(int));
	index = 0;
	while (index < arr_size)
	{
		arr[index] = index + min;
		index++;
	}
	return (arr);
}
