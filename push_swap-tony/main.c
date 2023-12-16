/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:17:08 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:10:21 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		capacity;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;

	check_valid_input(av, ac, &capacity, &av);
	init_stack(&a, &size_a, capacity, av);
	check_duplicate(a, capacity);
	check_if_sort(a, size_a);
	b = malloc(capacity * (sizeof(int)));
	size_b = 0;
	push_swap(&a, &size_a, &b, &size_b);
	free(a);
	free(b);
	return (0);
}

/*
	printf("Initialized Stack A: "); //DELETE LATER
    for (int i = 0; i < size_a; i++)
	{
    	printf("%d ", a[i]);
    }
    printf("\n");
	printf("Initialized Stack B: "); //DELETE LATER
    for (int i = 0; i < size_b; i++)
	{
    	printf("%d ", b[i]);
    }
    printf("\n");

	push_swap(&a, &size_a, &b, &size_b);


	printf("Stack A: "); //DELETE LATER
	for (int i = 0; i < size_a; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Stack B: "); //DELETE LATER
	for (int i = 0; i < size_b; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
*/
