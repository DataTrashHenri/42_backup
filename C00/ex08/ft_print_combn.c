/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrock <hrock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:38:34 by hrock             #+#    #+#             */
/*   Updated: 2025/07/30 21:47:02 by hrock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void continueCombination(char combinationSoFar[], int workingIndex, int limit) {
    //case n=1
    if (limit==1)
    {
        for(int i=0;i<9;i++) {
            combinationSoFar[0]=(char) (i+48);
            char tmp =combinationSoFar[0];
            write(1,&tmp,1);
            char comma =',';
            write(1,&comma,1);

        }
        combinationSoFar[0]= (char)(9+48);
        char tmp =combinationSoFar[0];
        write(1,&tmp,1);
        return;
    }
    
    //abortion
    if(workingIndex==limit-1) {
        for (int i = (combinationSoFar[workingIndex-1]-48)+1; i < 10; i++)
        {
            combinationSoFar[workingIndex]=(char)(i+48);
            for (int i = 0; i < limit; i++)
            {
                char tmp =combinationSoFar[i];
                write(1,&tmp,1);
            }
            // check if Last last number
            int checkNum= 10-limit;
            int isLastNumber = 1;

            for(int i=0;i<limit;i++) {
                if ((((int)combinationSoFar[i])-48)!=(checkNum+i))
                {
                    isLastNumber=0;
                }
                
            }
            if (isLastNumber==0)
            {
                char comma=',';
                write(1,&comma,1);
            }
            
            
        }
        return;
        
    }
    //normal case
    for (int i = (int) ((combinationSoFar[workingIndex-1])-48)+1; i < 10; i++)
    {
        combinationSoFar[workingIndex]=(char)(i+48);
        continueCombination(combinationSoFar,workingIndex+1,limit);
    }
    
}

void ft_print_combn(int n) {
    char wholeCombination[n];
    for (int i = 0; i < n; i++)
    {
        wholeCombination[i]='O';
    }

    /*for (int i = 0; i < n; i++)
    {
        char current = wholeCombination[i];
        write(1,&current,1);
    }*/
    if(n!=1) {
        for (int i = 0; i < 9; i++)
        {
            wholeCombination[0]=(char)(i+48);
            continueCombination(wholeCombination,1,n);
        }
    } else {
        continueCombination(wholeCombination,1,n);
    }
    
    
}
