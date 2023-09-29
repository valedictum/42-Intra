/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 12:38:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = read_values_and_push_onto_stack_a(argc, argv);
	if (!stack_a || checkdup(stack_a))
	{
		ps_free(&stack_a);
		ps_print_error();
	}
	printf("Stack A elements (before sorting): ");
	print_stack(stack_a);
	if (!check_if_sorted(stack_a))
		sort_elements(&stack_a);
	printf("Stack A elements (after sorting): ");
	print_stack(stack_a);
	ps_free(&stack_a);
	return (0);
}
