/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:52:10 by hrock             #+#    #+#             */
/*   Updated: 2025/07/31 22:21:07 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		current_entry;
	int		current_entry_b;
	int		tmp;
	int		max_repetition;

	current_entry = 0;
	max_repetition = size / 2;
	while (current_entry < max_repetition)
	{
		current_entry_b = (size - 1) - current_entry;
		tmp = tab[current_entry];
		tab[current_entry] = tab[current_entry_b];
		tab[current_entry_b] = tmp;
		current_entry++;
	}
}
