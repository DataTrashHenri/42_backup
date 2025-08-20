/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:26:51 by hrock             #+#    #+#             */
/*   Updated: 2025/08/02 18:53:59 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		src_size;

	src_size = 0;
	dest[src_size] = src[src_size];
	while (src[src_size] != '\0')
	{
		src_size++;
		dest[src_size] = src[src_size];
	}
	return (dest);
}
