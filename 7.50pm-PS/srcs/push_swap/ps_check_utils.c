/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:41:31 by atang             #+#    #+#             */
/*   Updated: 2023/11/12 19:53:37 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_checkdup(t_stack_node *stack_a)
{
	t_stack_node	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->value == temp->value)
				return (1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ps_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int is_valid_integer(long value){
    // Check if the value is within the valid integer range
    if (value >= INT_MIN && value <= INT_MAX) {
        return 1;
    }
    return 0;
}
 */
 
void	ps_check_stack_and_display_error(t_stack_node *stack_a)
{
	if (!stack_a || ps_checkdup(stack_a))
	{
		ps_free_stack(&stack_a);
		ps_error_message();
	}
}

int	ps_check_if_sorted(t_stack_node *stack_a)
{
	int	prev_value;

	prev_value = INT_MIN;
	while (stack_a)
	{
		if (prev_value > stack_a->value)
			return (0);
		prev_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}

bool is_sorted(t_stack_node *stack)
{
    while (stack != NULL && stack->next != NULL)
	{
        if (stack->rank > stack->next->rank) 
		{
            return false;
        }
        stack = stack->next;
    }
    return true;
}

int ps_check_if_sorted_descending(t_stack_node *stack_a)
{
    int prev_value = INT_MAX;

    while (stack_a)
    {
        if (prev_value < stack_a->value)
            return 0;
        prev_value = stack_a->value;
        stack_a = stack_a->next;
    }

    return 1;
}

