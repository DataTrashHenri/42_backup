/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:40:49 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 20:24:53 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0' && index < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}
