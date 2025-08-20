/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:51:17 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 11:56:05 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int num)
{
	int		index;

	if (num <= 1)
		return (0);
	index = 2;
	while (index < num)
	{
		if (num % index == 0)
			return (0);
		index++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!is_prime(nb++))
	{
	}
	return (--nb);
}
