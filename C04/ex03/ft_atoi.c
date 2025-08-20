/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:08:12 by hrock             #+#    #+#             */
/*   Updated: 2025/08/07 21:03:42 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isspace_(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	handle_signs(char *str, int index, int *flag)
{
	if (str[index] == '-')
		*flag += 1;
	else if (str[index] != '+')
		return (0);
	return (1);
}

int	find_num_length(char *str, int index, int *ascending)
{
	int		i;

	i = 0;
	while ((str[index + i] >= '0' && str[index + i] <= '9'))
	{
		if (*ascending == 0)
		{
			if (str[index + i +1] == (str[index + i] + 1))
				*ascending = 1;
			else if (str[index + i +1] == (str[index + i] - 1))
				*ascending = -1;
		}
		if ((str[index + i + 1] == str[index + i] + *ascending))
		{
			i++;
		}
		else
			return (++i);
	}
	return (i);
}

void	insert_num(char *str, int size, int *num, int global_index)
{
	int		index;
	int		multiplier;

	multiplier = 1;
	index = size - 1;
	while (index >= 0)
	{
		*num += (multiplier * (str[global_index + index] - 48));
		multiplier *= 10;
		index--;
	}
}

int	ft_atoi(char *str)
{
	int		num_size;
	int		global_index;
	int		flag;
	int		num;
	int		ascending;

	ascending = 0;
	flag = 0;
	global_index = 0;
	num = 0;
	while (isspace_(str[global_index++]) == 1)
	{
	}
	global_index--;
	while (handle_signs(str, global_index++, &flag) == 1)
	{
	}
	global_index--;
	num_size = find_num_length(str, global_index, &ascending);
	insert_num(str, num_size, &num, global_index);
	if (flag % 2 == 0)
	{
		return (num);
	}
	return (-num);
}
// int main()
// {
// 	char str[100] = "    +-+-+--1235";
// 	printf("%i", ft_atoi(str));
// }