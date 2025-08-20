/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:43:56 by hrock             #+#    #+#             */
/*   Updated: 2025/08/10 16:34:06 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	index;

	index = argc - argc;
	while (argv[0][index] != '\0')
		write(1, &(argv[0][index++]), 1);
	write(1, "\n", 1);
	return (0);
}
