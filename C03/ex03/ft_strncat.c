/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:34:49 by hrock             #+#    #+#             */
/*   Updated: 2025/08/05 06:58:05 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				dest_size;
	unsigned int	iterator;

	dest_size = 0;
	while (dest[dest_size] != '\0')
	{
		dest_size++;
	}
	iterator = 0;
	while (iterator < nb && src[iterator] != '\0')
	{
		dest[dest_size + iterator] = src[iterator];
		iterator++;
	}
	dest[dest_size + iterator] = '\0';
	return (dest);
}
