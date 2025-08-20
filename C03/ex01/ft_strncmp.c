/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:37:15 by hrock             #+#    #+#             */
/*   Updated: 2025/08/05 05:28:03 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0') && index < n)
	{
		if (s1[index] == '\0')
		{
			return (-1);
		}
		else if (s2[index] == '\0')
		{
			return (1);
		}
		if (s1[index] > s2[index])
			return (1);
		else if (s2[index] > s1[index])
			return (-1);
		index++;
	}
	return (0);
}
