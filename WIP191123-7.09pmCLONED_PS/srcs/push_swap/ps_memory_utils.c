/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_memory_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:37:36 by atang             #+#    #+#             */
/*   Updated: 2023/11/10 21:31:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ps_free_str(char **input_array_of_str)
{
	char	*str_ptr;

	if (!input_array_of_str)
		return ;
	while (*input_array_of_str)
	{
		str_ptr = *input_array_of_str;
		input_array_of_str++;
		free(str_ptr);
	}
	*input_array_of_str = NULL;
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
