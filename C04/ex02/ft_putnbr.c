/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:50:08 by hrock             #+#    #+#             */
/*   Updated: 2025/08/06 23:16:22 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	handle_division(int *divisor, int *nb, char *nb_char, int *index)
{
	nb_char[*index] = (int)(*nb / *divisor) + 48;
	*nb -= (*nb / *divisor) * *divisor;
}

void	print_respectively(char *str)
{
	int		has_started;
	int		index;

	has_started = 0;
	index = 0;
	while (index < 9)
	{
		if (has_started == 0)
		{
			if (str[index] != '0')
				has_started = 1;
		}
		if (has_started == 1)
		{
			write(1, &str[index], 1);
		}
		index++;
	}
	if (str[9] == '0')
		write(1, "0", 1);
	else
		write(1, &str[9], 1);
}

void	ft_putnbr(int nb)
{
	int			index;
	int			divisor;
	char		nb_char[10];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	divisor = 1000000000;
	index = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (index < 9)
	{
		handle_division(&divisor, &nb, &nb_char[0], &index);
		divisor /= 10;
		index++;
	}
	nb_char[9] = nb + 48;
	print_respectively(&nb_char[0]);
}
