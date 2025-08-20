/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:24:50 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 22:18:22 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_adress_from_int(unsigned long num)
{
	int		index;
	int		bit[4];
	int		total;
	char	*hexa_digits;
	char	out[16];

	hexa_digits = "0123456789abcdef";
	index = 60;
	while (index >= 0)
	{
		bit[0] = ((num >> index) & 1);
		bit[1] = ((num >> (index + 1)) & 1);
		bit[2] = ((num >> (index + 2)) & 1);
		bit[3] = ((num >> (index + 3)) & 1);
		total = 8 * bit[0] + 4 * bit[1] + 2 * bit[2] + bit[3];
		out[(64 - (index + 4)) / 4] = hexa_digits[total];
		index -= 4;
	}
	index = 0;
	while (index < 16)
	{
		write(1, &out[index], 1);
		index++;
	}
	write(1, ": ", 2);
}

void	print_hexa(char c)
{
	char	hexa_c[2];
	char	*hexa_digits;

	hexa_digits = "0123456789abcdef";
	hexa_c[0] = hexa_digits[(int)(c / 16)];
	hexa_c[1] = hexa_digits[(int)(c % 16)];
	write(1, &hexa_c[0], 1);
	write(1, &hexa_c[1], 1);
}

void	print_full_hex_adress(int *addr, int index, unsigned int *rows)
{
	while (index < 16 && *((char *)addr + index + *rows) != '\0')
	{
		print_hexa(*((char *)addr + index + *rows));
		print_hexa(*((char *)addr + index + *rows + 1));
		write(1, " ", 1);
		index += 2;
	}
	while (index < 16)
	{
		write(1, "     ", 5);
		index += 2;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	rows;
	int				index;
	char			current_char;

	rows = 0;
	while (rows < (size * 16))
	{
		index = 0;
		print_adress_from_int((unsigned long)(&addr + rows));
		print_full_hex_adress(addr, index, &rows);
		while (index < 16 && *((char *)addr + index + rows) != '\0')
		{
			current_char = *((char *)addr + index + rows);
			if (!(current_char >= 32) || !(current_char <= 126))
			{
				write(1, ".", 1);
			}
			else
				write(1, addr + index + rows, 1);
			index++;
		}
		write(1, "\n", 1);
		rows += 16;
	}
	return (addr);
}
