/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:43:32 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 10:10:02 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		iter;
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	iter = 0;
	while (iter < index)
	{
		if (str[iter] >= 97 && str[iter] <= 122)
		{
			str[iter] -= 32;
		}
		iter++;
	}
	return (str);
}
