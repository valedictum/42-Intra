/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:11:58 by atang             #+#    #+#             */
/*   Updated: 2023/09/17 14:25:04 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;

	if (argc < 2)
	{
		printf ("Usage: %s <value1> <value2> ... <valueN>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stack_a = read_values_and_push_onto_stack_a(argc, argv);
	stack_b = NULL;
	printf("Stack A elements (before sorting): ");
	print_stack(stack_a);
	num_elements = argc -1;
	if (num_elements == 2)
		sort_two_elements(&stack_a);
	else if (num_elements == 3)
		sort_three_elements(&stack_a);
	else if (num_elements == 5)
		sort_five_elements(&stack_a, &stack_b);
	printf("Stack A elements (after sorting): ");
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

/*
	Initialise Stack A and Stack B (empty linked lists) 
	
	Parse input and push numbers onto Stack A
	
	While Stack A not empty:
		- find the smallest (or largest) number in Stack A (call it N)
		- while the top element of Stack A is NOT N:
			- if the top element is closer to the top, rotate Stack A
			- otherwise, reverse rotate Stack A
		- push N onto Stack B
		- pop N from Stack A
	
	While Stack B is NOT empty:
		- push the top element of Stack B onto Stack A
		- pop the top element from Stack B

	Stack A should now have the sorted numbers in ascending order
*/