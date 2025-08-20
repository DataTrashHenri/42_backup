/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:18:51 by hrock             #+#    #+#             */
/*   Updated: 2025/07/31 17:29:31 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	char	current;
	int		length_counter;

	length_counter = 0;
	current = str[length_counter];
	while (current != '\0')
	{
		length_counter++;
		current = str[length_counter];
	}
	write (1, str, length_counter);
}
