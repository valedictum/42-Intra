/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:22:25 by atang             #+#    #+#             */
/*   Updated: 2024/01/28 17:22:55 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
		int *operation_count, int num_elements)
{
	if (num_elements == 2)
	{
		ps_sort_2_numbers(stack_a, operation_count);
	}
	else if (num_elements == 3)
	{
		ps_sort_3_numbers(stack_a, operation_count);
	}
	else if (num_elements == 4 || num_elements == 5)
	{
		ps_sort_5_numbers(stack_a, stack_b, operation_count);
	}
	else if (num_elements == 6 || num_elements == 7)
	{
		chunk_sort_2(stack_a, stack_b, operation_count);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	else if ((num_elements >= 8 && num_elements <= 19) || num_elements % 3 == 0)
	{
		chunk_sort_3(stack_a, stack_b, operation_count);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	else if ((num_elements >= 20 && num_elements <= 49))
	{
		chunk_sort_4(stack_a, stack_b, operation_count);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	else if (num_elements >= 50 && num_elements <= 499)
	{
		chunk_sort_100(stack_a, stack_b, operation_count);
		insertion_sort(stack_a, stack_b, operation_count);
	}
	else
	{
		chunk_sort_500(stack_a, stack_b, operation_count);
		insertion_sort(stack_a, stack_b, operation_count);
	}
}

/*
// WORKING
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
	choose_sorting_algorithm(&stack_a, &stack_b, &operation_count,
		num_elements);
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
*/

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				num_elements;
	int				operation_count;
	//char			**split_arguments;

	stack_a = NULL;
	stack_b = NULL;
	num_elements = 0;
	operation_count = 0;
	argv++;
	if (argc < 2)
	{
		//ft_printf("Error: Not enough arguments provided.\n");
		return (1);
	}
	if (argc == 2)
	{
		if ((argv[1][0] == '\"') && (argv[1][ps_strlen(argv[1]) - 1] == '\"'))
		{
			split_arguments = ft_split(argv[1], ' ');
			if (split_arguments == NULL)
			{
				//ft_printf("Error splitting arguments.\n");
				return (1);
			}
			ps_parse_and_insert_arguments(&stack_a, split_arguments,
				&num_elements);
			free(split_arguments); // Free memory allocated by ft_split
		}
	}
	else
		ps_parse_and_insert_arguments(&stack_a, argv, &num_elements);
	ps_stack_rank(stack_a);
	ps_check_stack_and_display_error(stack_a);
	choose_sorting_algorithm(&stack_a, &stack_b, &operation_count,
		num_elements);
	ps_free_stack(&stack_a);
	ps_free_stack(&stack_b);
	return (0);
}
