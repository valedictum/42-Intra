/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/11/05 18:25:18 by atang            ###   ########.fr       */
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
