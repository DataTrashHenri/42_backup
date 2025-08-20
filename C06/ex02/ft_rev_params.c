/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:13:27 by hrock             #+#    #+#             */
/*   Updated: 2025/08/15 19:53:36 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	arg;
	int	index;

	arg = argc - 1;
	while (arg > 0)
	{
		index = 0;
		while (argv[arg][index] != '\0')
			write(1, &argv[arg][index++], 1);
		arg--;
		write(1, "\n", 1);
	}
	return (0);
}
