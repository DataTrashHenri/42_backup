/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:43:36 by hrock             #+#    #+#             */
/*   Updated: 2025/08/14 22:05:49 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	str_len(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*new_str;
	int		index;

	src_len = str_len(src);
	new_str = malloc(src_len + 1);
	index = 0;
	while (index < src_len)
	{
		new_str[index] = src[index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
