/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:58:25 by hrock             #+#    #+#             */
/*   Updated: 2025/08/15 19:47:09 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
//#include<stdio.h>

int	size_str_at(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	write_str_at(char *str, int where, char *write)
{
	int	index;

	index = 0;
	while (write[index] != '\0')
	{
		str[where + index] = write[index];
		index++;
	}
}

void	map_to_flat(int size, char **strs, char *sep, char *arr)
{
	int	index;
	int	iter;

	index = 0;
	iter = 0;
	while (index < size)
	{
		write_str_at(arr, iter, strs[index]);
		iter += size_str_at(strs[index]);
		if (index != (size - 1))
		{
			write_str_at(arr, iter, sep);
			iter += size_str_at(sep);
		}	
		index++;
	}
	arr[iter] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	int		index;
	char	*arr;

	total_size = 0;
	index = 0;
	while (index < size)
	{
		total_size += size_str_at(strs[index]);
		index++;
	}
	arr = malloc((total_size + (size - 1) * (size_str_at(sep))) + 1);
	map_to_flat(size, strs, sep, arr);
	return (arr);
}

// int main()
// {
// 	char *str[10] = {"hallo","welt","allesklar","ok"};
// 	char sep[3] = " , ";
// 	ft_strjoin(4,str,sep);

// }