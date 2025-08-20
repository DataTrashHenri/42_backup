/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:25:18 by hrock             #+#    #+#             */
/*   Updated: 2025/07/31 22:58:38 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *array, int ind1, int ind2)
{
	int		tmp;

	tmp = array[ind1];
	array[ind1] = array[ind2];
	array[ind2] = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		seperate_index;
	int		tmp;
	int		smallest;
	int		index;

	seperate_index = 0;
	while (seperate_index < (size - 1))
	{
		smallest = seperate_index;
		index = seperate_index + 1;
		while (index < size)
		{
			if (tab[index] < tab[smallest])
			{
				smallest = index;
			}
			index++;
		}
		swap(tab, smallest, seperate_index);
		seperate_index++;
	}
}
