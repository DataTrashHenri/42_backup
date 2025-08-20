/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:13:12 by hrock             #+#    #+#             */
/*   Updated: 2025/08/18 10:16:06 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char *av[])
{
	t_stock_str	*strs;
	int			index;
	int			inner_index;

	strs = malloc(sizeof(t_stock_str) * (ac + 1));
	index = 0;
	while (index < ac)
	{
		inner_index = 0;
		strs[index].str = av[index];
		strs[index].copy = malloc(str_len(av[index]) + 1);
		while (av[index][inner_index] != '\0')
		{
			strs[index].copy[inner_index] = av[index][inner_index];
			inner_index++;
		}
		strs[index].size = inner_index;
		index++;
	}
	strs[index].str = 0;
	return (strs);
}
