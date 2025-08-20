/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:32:36 by hrock             #+#    #+#             */
/*   Updated: 2025/07/30 13:53:58 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	first_loop;
	char	second_loop;
	char	third_loop;

	first_loop = '0';
	while (first_loop <= '7')
	{
		second_loop = first_loop + 1;
		while (second_loop <= '8')
		{
			third_loop = second_loop + 1;
			while (third_loop <= '9')
			{
				write(1, &first_loop, 1);
				write(1, &second_loop, 1);
				write(1, &third_loop, 1);
				if ((100 * first_loop + 10 * second_loop + third_loop) != 6117)
					write(1, ", ", 2);
				third_loop++;
			}
			second_loop++;
		}
		first_loop++;
	}
}
