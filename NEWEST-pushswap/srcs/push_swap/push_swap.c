/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/10/07 16:21:11 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;

	stack_a = NULL;
	stack_b = NULL;
	num_elements = 0;
	argv++;
	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments provided.\n");
		return (1);
	}
	ps_parse_and_insert_arguments(&stack_a, argv, &num_elements);
	ps_check_stack_and_display_error(stack_a);
	ft_printf("\n");
	ft_printf("Stack A elements (before sorting): ");
	ps_print_stack(stack_a);
	ft_printf("\n");
	if (num_elements == 2)
		ps_sort_2_numbers(&stack_a);
	else if (num_elements == 3)
		ps_sort_3_numbers(&stack_a);
	else if (num_elements == 5)
		ps_sort_5_numbers(&stack_a, &stack_b);
	else
		insertion_sort(&stack_a, &stack_b);
	ft_printf("Stack A elements (after sorting): ");
	ps_print_stack(stack_a);
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
