/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:28:20 by hrock             #+#    #+#             */
/*   Updated: 2025/07/31 17:51:05 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
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
	return (length_counter);
}
