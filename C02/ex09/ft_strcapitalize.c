/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:15:56 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 20:12:52 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	get_arr_size(char *str)
{
	int		size;

	size = 0;
	while (*str != '\0')
	{
		str++;
		size++;
	}
	return (size);
}

int	is_seperating_char(char c)
{
	if (c == ' ' || c == '+' || c == '-')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		str_size;
	int		iterator;

	str_size = get_arr_size(str);
	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	iterator = 1;
	while (iterator < str_size)
	{
		if (str[iterator] >= 'a' && str[iterator] <= 'z')
		{
			if (is_seperating_char(str[iterator - 1]) == 1)
				str[iterator] -= 32;
		}
		else if ((*(str + iterator) >= 'A') && (*(str + iterator) <= 'Z'))
		{
			if (is_seperating_char(str[iterator - 1]) != 1)
				str[iterator] += 32;
		}
		iterator++;
	}
	return (str);
}
