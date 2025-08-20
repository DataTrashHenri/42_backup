/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:53:29 by hrock             #+#    #+#             */
/*   Updated: 2025/08/05 17:39:20 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		dest_size;
	int		iterator;

	dest_size = 0;
	while (dest[dest_size] != '\0')
	{
		dest_size++;
	}
	iterator = 0;
	while (src[iterator] != '\0')
	{
		dest[dest_size + iterator] = src[iterator];
		iterator++;
	}
	dest[iterator + dest_size] = '\0';
	return (dest);
}
