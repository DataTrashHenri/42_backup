/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:26:14 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 22:10:40 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_hexa(char c)
{
	char	hexa_c[2];
	char	*hexa_digits;

	hexa_digits = "0123456789abcdef";
	hexa_c[0] = hexa_digits[(int)(c / 16)];
	hexa_c[1] = hexa_digits[(int)(c % 16)];
	write(1, "\\", 1);
	write(1, &hexa_c[0], 1);
	write(1, &hexa_c[1], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;
	int		current;

	index = 0;
	while (str[index] != '\0')
	{
		current = str[index];
		if (!(current >= 32) || !(current <= 126))
		{
			print_hexa(current);
		}
		else
			write(1, &str[index], 1);
		index++;
	}
}
