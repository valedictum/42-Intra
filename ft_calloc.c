/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:19:56 by atang             #+#    #+#             */
/*   Updated: 2023/07/21 12:38:52 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     calloc, free, malloc, realloc, reallocf, valloc, aligned_alloc -- memory 
	 allocation

SYNOPSIS
     #include <stdlib.h>

     void *
     calloc(size_t count, size_t size);

     void
     free(void *ptr);

     void *
     malloc(size_t size);

DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions 
	 allocate memory.  The allocated memory is aligned such that it can be 
	 used for any data type, including AltiVec- and SSE-related types.  The 
	 aligned_alloc() function allocates memory with the requested alignment. 
	 The free() function frees allocations that were created via the preceding 
	 allocation functions.

     The malloc() function allocates size bytes of memory and returns a pointer 
	 to the allocated mem-
     ory.

     The calloc() function contiguously allocates enough space for count 
	 objects that are size bytes of memory each and returns a pointer to the 
	 allocated memory.  The allocated memory is filled with bytes of value zero.

	 The free() function deallocates the memory allocation pointed to by ptr. 
	 If ptr is a NULL pointer, no operation is performed.

RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and 
	 aligned_alloc() functions return a pointer to allocated memory.  If there 
	 is an error, they return a NULL pointer and set errno to ENOMEM.

	The free() function does not return a value.
*/

#include "libft.h"

static void	*calloc_zero(void)
{
	void	*memory;

	memory = malloc(1);
	if (memory != NULL)
		ft_memset(memory, 0, 1);
	return (memory);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*memory;

	if (nmemb == 0 || size == 0)
		return (calloc_zero());
	if (SIZE_MAX / nmemb < size)
	{
		printf("Integer overflow during memory allocation.\n");
		return (NULL);
	}
	total_size = nmemb * size;
	if (nmemb != total_size / size)
		return (NULL);
	memory = malloc(total_size);
	if (memory == NULL)
	{
		printf("Memory allocation failed.\n");
		return (NULL);
	}
	ft_memset(memory, 0, total_size);
	return (memory);
}

/* 
int	main(void)
{
	int	nmemb = 5;
	int	size = sizeof(int);
	int	*array = (int*)ft_calloc(nmemb, size);
	int	i = 0;

	if (array == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	while (i < nmemb)
	{
		array[i] = i + 1;
		printf("%d ", array[i]);
		i++;
	}
	free(array);
	return (0);
}

 */
