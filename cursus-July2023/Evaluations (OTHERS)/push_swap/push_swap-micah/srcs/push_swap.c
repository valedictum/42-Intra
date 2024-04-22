/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:21 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 15:55:09 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_numbers(int *numbers, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	initialise_stacks(&stack_a, &stack_b, numbers, size);
	if (is_it_sorted(stack_a) == false)
	{
		if (stack_a->size == 2)
			run_operation(stack_a, NULL, SA);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 4)
			sort_four(stack_a, stack_b);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
		else if (stack_a-> size > 5 && stack_a->size < 500)
			cost_sort(stack_a, stack_b);
		else
			some_internet_sort(stack_a, stack_b);
	}
	free_stacks(stack_a, stack_b);
}

void	push_swap(int argc, char **argv)
{
	int	*numbers;
	int	size;

	if (argc == 2)
		parse_argument(argv[1], &numbers, &size);
	else
		parse_multi_arguments(argv, &numbers, &size);
	sort_numbers(numbers, size);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
