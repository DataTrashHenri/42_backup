/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:33:30 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 12:58:20 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	expo;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	expo = nb;
	while (--power > 0)
	{
		nb *= expo;
	}
	return (nb);
}
