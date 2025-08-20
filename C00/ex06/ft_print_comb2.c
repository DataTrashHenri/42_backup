/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2RETRY.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:19:58 by hrock             #+#    #+#             */
/*   Updated: 2025/07/31 12:31:09 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_to_ascii(int first, int second)
{
	char	first_digit;
	char	second_digit;
	char	third_digit;
	char	fourth_digit;

	first_digit = (first / 10) + 48;
	second_digit = (first % 10) + 48;
	third_digit = (second / 10) + 48;
	fourth_digit = (second % 10) + 48;
	write(1, &first_digit, 1);
	write(1, &second_digit, 1);
	write(1, " ", 1);
	write(1, &third_digit, 1);
	write(1, &fourth_digit, 1);
	if (first == 98)
	{
		if (second == 99)
		{
			return ;
		}
	}
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	first_num;
	int	second_num;

	first_num = 0;
	second_num = 1;
	while (first_num < 99)
	{
		second_num = first_num + 1;
		while (second_num <= 99)
		{
			print_to_ascii(first_num, second_num);
			second_num++;
		}
		first_num++;
	}
}
