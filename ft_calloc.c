/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:19:56 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 16:20:20 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_calloc.c
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);

Description
The calloc() function allocates memory for an array of nmemb elements of size 
bytes each and returns a pointer to the allocated memory. The memory is set to 
zero. If nmemb or size is 0, then calloc() returns either NULL, or a unique 
pointer value that can later be successfully passed to free(). 
*/

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *memory;
    memory = malloc(nmemb * size);
    
    if (memory != NULL)
    {
        memset(memory, 0, nmemb * size);
    }  
    return (memory);
}

int main()
{
    int nmemb = 5;
    int size = sizeof(int);
    
    int *array = (int*)ft_calloc(nmemb, size);
    
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }
    for (int i = 0; i < nmemb; i++)
    {
        array[i] = i + 1;
        printf("%d", array[i]);
    }
    free(array);
    return (0);
}
