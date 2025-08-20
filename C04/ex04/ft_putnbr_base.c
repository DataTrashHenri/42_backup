/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:15:32 by hrock             #+#    #+#             */
/*   Updated: 2025/08/09 01:42:40 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	check_invalid_length(char *base, int num, int base_size)
{
	char	tmp;

	if (num == -2147483648)
	{
		tmp = base[2147483648 % base_size];
		ft_putnbr_base((-2147483648) / base_size, base);
		write(1, &tmp, 1);
		return (0);
	}
	if (*base == '\0')
		return (0);
	else if (base[1] == '\0')
		return (0);
	return (1);
}

int	validate_base(char *base, int nbr, int base_size)
{
	int	i;
	int	j;

	if (!check_invalid_length(base, nbr, base_size))
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	char	num_char[32];
	int		index;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (!validate_base(base, nbr, base_size))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	index = 31;
	num_char[index--] = base[nbr % base_size];
	nbr /= base_size;
	while (nbr)
	{
		num_char[index--] = base[nbr % base_size];
		nbr /= base_size;
	}
	index++;
	while (index < 32)
		write(1, &num_char[index++], 1);
}
