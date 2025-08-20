/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:32:04 by hrock             #+#    #+#             */
/*   Updated: 2025/08/05 07:19:54 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				iterator;
	int				dest_size;
	int				src_size;
	unsigned int	index_in_dest;

	src_size = get_size(src);
	dest_size = get_size(dest);
	iterator = 0;
	index_in_dest = dest_size + iterator;
	while (iterator < src_size && index_in_dest < (size - 1))
	{
		dest[dest_size + iterator] = src[iterator];
		iterator ++;
		index_in_dest = dest_size + iterator;
	}
	dest[index_in_dest] = '\0';
	return (dest_size + src_size);
}
