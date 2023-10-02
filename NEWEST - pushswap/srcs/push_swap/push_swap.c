/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 17:51:37 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ps_sort_beyond_3_and_5_numbers(&stack_a, &stack_b);
	ft_printf("Stack A elements (after sorting): ");
	ps_print_stack(stack_a);
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
