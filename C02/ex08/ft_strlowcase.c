/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:10:32 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 10:14:05 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		iter;
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	iter = 0;
	while (iter < index)
	{
		if (str[iter] >= 65 && str[iter] <= 90)
		{
			str[iter] += 32;
		}
		iter++;
	}
	return (str);
}
