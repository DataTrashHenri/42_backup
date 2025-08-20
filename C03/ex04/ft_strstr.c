/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:29:27 by hrock             #+#    #+#             */
/*   Updated: 2025/08/04 18:28:25 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_at_index(char *src, char *needle, int index)
{
	int		iterator;

	iterator = 0;
	while (*(needle + iterator) != '\0')
	{
		if (*(src + index + iterator) != *(needle + iterator))
		{
			return (0);
		}
		iterator++;
	}
	return (1);
}

int	get_size(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		str_size;
	int		to_find_size;
	int		iterator;

	str_size = get_size(str);
	to_find_size = get_size(to_find);
	iterator = 0;
	while (iterator + to_find_size <= str_size)
	{
		if (str_at_index(str, to_find, iterator) == 1)
		{
			return (str + iterator);
		}
		iterator++;
	}
	return (0);
}
