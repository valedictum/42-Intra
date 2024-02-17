/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2024/02/16 22:13:16 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_stack_node **stack_a, t_stack_node **stack_b,
		int *operation_count, int num_elements)
{
	if (num_elements == 2)
		sort_2(stack_a, operation_count);
	else if (num_elements == 3)
		sort_3(stack_a, operation_count);
	else if (num_elements <= 10)
		sort_5(stack_a, stack_b, operation_count);
	else if (num_elements >= 500)
	{
		chunk_sort_3(stack_a, stack_b, operation_count);
		//ft_printf ("After chunk A:\n");
		//print_stack(*stack_a);
		//ft_printf ("After chunk B:\n");
		//print_stack(*stack_b);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	/*
	else if (num_elements < 500)
	{
		chunk_sort_500(stack_a, stack_b, operation_count);
		//ft_printf ("After chunk A:\n");
		//print_stack(*stack_a);
		//ft_printf ("After chunk B:\n");
		//print_stack(*stack_b);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	*/
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;
	int				operation_count;
	char			**split_arguments;

	stack_a = NULL;
	stack_b = NULL;
	num_elements = 0;
	operation_count = 0;
	if (argc < 2)
		exit (1);
	if (argc == 2)
	{
		split_arguments = ft_split(argv[1], ' ');
		if (split_arguments == NULL)
		{
			ft_printf("Split fail\n");
			return (1);
		}
		parse_and_insert(&stack_a, split_arguments, &num_elements);
		free_split_arguments(split_arguments);
	}
	else
		parse_and_insert(&stack_a, &argv[1], &num_elements);
	//ft_printf ("Before:\n");
	//print_stack(stack_a);
	//ft_printf ("Before stack error:\n");
	check_stack_and_display_error(stack_a);
	//ft_printf ("Before stack_rank:\n");
	stack_rank(stack_a);
	//ft_printf ("Before choose sort:\n");
	choose_sort(&stack_a, &stack_b, &operation_count, num_elements);
	//ft_printf ("After:\n");
	//print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
