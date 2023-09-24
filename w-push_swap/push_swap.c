/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:09:26 by atang             #+#    #+#             */
/*   Updated: 2023/09/24 18:56:57 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*read_values_and_push_onto_stack_a(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*new_node;
	int				i;
	int				value;

	stack_a = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		value = ps_atoi(argv[i]);
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (new_node == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		new_node->value = value;
		new_node->next = stack_a;
		stack_a = new_node;
		i--;
	}
	return (stack_a);
}

/* 
int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_stack_node	*current_a;
	t_stack_node	*temp;

	if (argc < 2)
	{
		printf ("Usage: %s <value1> <value2> ... <valueN>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stack_a = read_values_and_push_onto_stack_a(argc, argv);
	stack_b = NULL;
	printf("Stack A elements: ");
	current_a = stack_a;
	while (current_a != NULL)
	{
		printf("%d ", current_a->value);
		current_a = current_a->next;
	}
	printf("\n");
	while (stack_a != NULL)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	return (0);
}
 */