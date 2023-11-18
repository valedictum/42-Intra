/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/11/18 18:57:39 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char *argv[])
{
    t_stack_node *stack_a;
    t_stack_node *stack_b;
    int num_elements;
    int operation_count;

    stack_a = NULL;
    stack_b = NULL;
    num_elements = 0;
    operation_count = 0;

    argv++;

    printf("Before argument check\n");

    if (argc < 2) {
        ft_printf("Error: Not enough arguments provided.\n");
        return (1);
    }
    printf("After argument check\n");
    if (argc == 2 && (argv[1][0] == '\"') && (argv[1][ps_strlen(argv[1]) - 1] == '\"'))
	{
        printf("Inside quoted argument check\n");
		if (stack_a == NULL)
		{
			ft_printf("Error: Stack not properly initialized.\n");
			return (1);
		}
		// Ensure num_elements is a valid value (greater than or equal to zero)
		if (num_elements < 0)
		{
			ft_printf("Error: Invalid value for num_elements.\n");
			return (1);
		}
        ps_parse_args_in_quotes(&argv[1], &stack_a, &num_elements);
    }
	else
	{
        printf("Inside normal argument check\n");
		if (stack_a == NULL)
		{
			ft_printf("Error: Stack not properly initialized.\n");
			return (1);
		}
		// Ensure num_elements is a valid value (greater than or equal to zero)
		if (num_elements < 0)
		{
			ft_printf("Error: Invalid value for num_elements.\n");
			return (1);
		}
        ps_parse_and_insert_arguments(&stack_a, argv, &num_elements);
    }
    printf("After argument parsing\n");
    // Add similar printf statements throughout the rest of your code blocks...
    // Example:
    printf("Before stack rank\n");
    ps_stack_rank(stack_a);
    printf("After stack rank\n");
	if (num_elements == 2)
		ps_sort_2_numbers(&stack_a, &operation_count);
	else if (num_elements == 3)
		ps_sort_3_numbers(&stack_a, &operation_count);
	else if (num_elements == 4 || num_elements == 5)
		ps_sort_5_numbers(&stack_a, &stack_b, &operation_count);
	else if (num_elements == 7 || num_elements == 9)
	{
		chunk_sort_3(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else if (num_elements == 8)
	{
		chunk_sort_4(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else if (num_elements == 6 || (num_elements >= 10 && num_elements <= 499))
	{
		chunk_sort_100(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else
	{
		chunk_sort_500(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
    printf("Before freeing stacks\n");
    ps_free_stack(&stack_a);
    ps_free_stack(&stack_b);
    printf("After freeing stacks\n");
    return (0);
}
/*
// CHECKER MAIN
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
	if (argc == 2 && (argv[1][0] == '\"') && (argv[1][ps_strlen(argv[1]) - 1] == '\"'))
		ps_parse_args_in_quotes(argv[1], &stack_a, &num_elements);
    else 
		ps_parse_and_insert_arguments(&stack_a, argv, &num_elements);
	ps_stack_rank(stack_a); 
	ps_check_stack_and_display_error(stack_a);
	if (num_elements == 2)
		ps_sort_2_numbers(&stack_a, &operation_count);
	else if (num_elements == 3)
		ps_sort_3_numbers(&stack_a, &operation_count);
	else if (num_elements == 4 || num_elements == 5)
		ps_sort_5_numbers(&stack_a, &stack_b, &operation_count);
	else if (num_elements == 7 || num_elements == 9)
	{
		chunk_sort_3(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else if (num_elements == 8)
	{
		chunk_sort_4(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else if (num_elements == 6 || (num_elements >= 10 && num_elements <= 499))
	{
		chunk_sort_100(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else
	{
		chunk_sort_500(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
*/

/*
// MAIN THAT PRINTS (stacks, operation count etc.)
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
	else if (num_elements >= 100 && num_elements <= 499)
	{
		chunk_sort_100(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	else
	{
		chunk_sort_500(&stack_a, &stack_b, &operation_count);
		insertion_sort(&stack_a, &stack_b, &operation_count);
	}
	ps_stack_rank(stack_a);
	ps_update_positions(stack_a);
	// PRINT STACK A AFTER SORTING AND TOTAL OPERATIONS COUNT
	ft_printf("Stack A elements (after sorting):\n");
	ps_print_stack_start_finish(stack_a);
	ft_printf("Total operations: %d\n", operation_count);
	ft_printf("\n");
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
*/


