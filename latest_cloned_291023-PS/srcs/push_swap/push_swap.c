/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/10/29 20:23:29 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
static void rotate_until_smallest_on_top(t_stack_node **stack_a, int *operation_count)
{
    int min_rank = INT_MAX; // Initialize min_rank to a large value
    t_stack_node *current = *stack_a;

    while (current != NULL)
    {
        if (current->rank < min_rank)
        {
            min_rank = current->rank;
        }
        current = current->next;
    }

    current = *stack_a;
    while (current->rank != min_rank)
    {
        ra(stack_a, operation_count);
        current = *stack_a;
    }
}
*/

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;
	int				operation_count;

	stack_a = NULL;
	stack_b = NULL;
	num_elements = 0;
	operation_count = 0;
	argv++;
	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments provided.\n");
		return (1);
	}
    ps_parse_and_insert_arguments(&stack_a, argv, &num_elements);
	ps_stack_rank(stack_a); 
	ps_check_stack_and_display_error(stack_a);
	ft_printf("\n");
	ft_printf("Stack A elements (before sorting):\n");
	ps_print_stack_start_finish(stack_a);
	ft_printf("\n");
	if (num_elements == 2)
		ps_sort_2_numbers(&stack_a, &operation_count);
	else if (num_elements == 3)
		ps_sort_3_numbers(&stack_a, &operation_count);
	else if (num_elements == 4 || num_elements == 5)
		ps_sort_4_or_5_numbers(&stack_a, &stack_b, &operation_count);
	else
	chunk_sort(&stack_a, &stack_b, &operation_count);
	insertion_sort(&stack_a, &stack_b, &operation_count);
		//(ORIGINAL) insertion_sort(&stack_a, &stack_b, &operation_count);
	ps_stack_rank(stack_a);
	ps_update_positions(stack_a);
	ft_printf("Stack A elements (after sorting):\n");
	ps_print_stack_start_finish(stack_a);
	ft_printf("Total operations: %d\n", operation_count);
	ft_printf("\n");
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}

/* 
int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;

	stack_a = ps_read_values_and_push_onto_stack_a(argc, argv);
	stack_b = NULL;
	if (!stack_a || ps_checkdup(stack_a))
	{
		ps_free_stack(&stack_a);
		ps_error_message();
	}
	ft_printf("Stack A elements (before sorting): ");
	ps_print_stack(stack_a);
	num_elements = argc -1;
	if (num_elements == 2)
		ps_sort_2_numbers(&stack_a);
	else if (num_elements == 3)
		ps_sort_3_numbers(&stack_a);
	else if (num_elements == 5)
		ps_sort_5_numbers(&stack_a, &stack_b);
	else
		ps_sort_beyond_5_numbers(&stack_a, &stack_b);
	ft_printf("Stack A elements (after sorting): ");
	ps_print_stack(stack_a);
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
*/
