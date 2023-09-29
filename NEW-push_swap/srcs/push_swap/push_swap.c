/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 14:47:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = ps_read_values_and_push_onto_stack_a(argc, argv);
	if (!stack_a || ps_checkdup(stack_a))
	{
		ps_free_stack(&stack_a);
		ps_error_message();
	}
	ft_printf("Stack A elements (before sorting): ");
	ps_print_stack(stack_a);
	if (!ps_check_if_sorted(stack_a))
		ps_sort(&stack_a);
	ft_printf("Stack A elements (after sorting): ");
	ps_print_stack(stack_a);
	ps_free_stack(&stack_a);
	return (0);
}
