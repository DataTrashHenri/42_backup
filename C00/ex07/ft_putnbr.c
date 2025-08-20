/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:59:21 by hrock             #+#    #+#             */
/*   Updated: 2025/07/30 16:36:25 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nb) {
    char minus = '-';
    //int hasStarted=0;
    if (nb<0)
    {
        write(1,&minus,1);
        nb=-nb;
    } else if(nb==0) {
        char zero = '0';
        write(1,&zero,1);
        return;
    }
    // count digits
    int digits=10;
    for (int i = 1000000000; i >=10; i/=10)
    {
        if (nb/i!=0)
        {
            break;
        }
        digits--;
    }
    int highestModulo=1;
    for (int i = 1; i < digits; i++)
    {   
        highestModulo*=10;
    }
    // iterate through everz digit and print it
    while (nb >0)
    {
        char currentDigit =(char) ((nb/highestModulo)+48);
        write(1,&currentDigit,1);
        nb = nb- ((nb/highestModulo)*highestModulo);
        highestModulo/=10;
    }
}
