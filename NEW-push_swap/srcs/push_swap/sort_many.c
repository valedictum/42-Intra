/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:29:47 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 18:03:25 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ps_sort_b_until_3(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				i;
	t_stack_node	*temp;

	while (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
	{
		temp = *stack_a;
		i = ps_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ps_case_rarb(*stack_a, *stack_b, temp->value))
				i = ps_use_rarb(stack_a, stack_b, temp->value, 'a');
			else if (i == ps_case_rrarrb(*stack_a, *stack_b, temp->value))
				i = ps_use_rrarrb(stack_a, stack_b, temp->value, 'a');
			else if (i == ps_case_rarrb(*stack_a, *stack_b, temp->value))
				i = ps_use_rarrb(stack_a, stack_b, temp->value, 'a');
			else if (i == ps_case_rrarb(*stack_a, *stack_b, temp->value))
				i = ps_use_rrarb(stack_a, stack_b, temp->value, 'a');
			else
				temp = temp->next;
		}
	}
}

int	ps_sort_onto_stack_b(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		ps_sort_b_until_3(stack_a, &stack_b);
	if (!ps_check_if_sorted(*stack_a))
		ps_sort_three_elements(stack_a);
	return (stack_b);
}

t_stack_node	**ps_sort_back_onto_stack_a(t_stack_node **stack_a,
					t_stack_node *stack_b)
{
	int				i;
	t_stack_node	*temp;

	while (*stack_b)
	{
		temp = stack_b;
		i = ps_rotate_type_ba(stack_a, stack_b);

		while (i >= 0)
		{
			if (i == ps_case_rarb_a(*stack_a, *stack_b, temp->value))
				i = ps_sort(stack_a, stack_b, temp->value, 'b');
			else if (i == ps_case_rarrb_a(*stack_a, *stack_b, temp->value))
				i = ps_use_rarrb(stack_a, stack_b, temp->value, 'b');
			else if (i == ps_case_rrarrb_a(*stack_a, *stack_b, temp->value))
				i = ps_use_rrarrb(stack_a, stack_b, temp->value, 'b');
			else if (i == ps_case_rrarb_a(*stack_a, *stack_b, temp->value))
				i = ps_use_rrarb(stack_a, stack_b, temp->value, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

void	ps_sort(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				i;

	stack_b = NULL;
	if (ps_find_stack_size(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = ps_sort_b(stack_a);
		stack_a = ps_sort_a(stack_a, &stack_b);
		i = ps_find_index(*stack_a, ps_find_min_value(*stack_a));
		if (i < ps_find_stack_size(*stack_a) - i)
		{
			while ((*stack_a)->value != ps_find_min_value(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack)->value != ps_find_min_value(*stack_a))
				rra(stack_a);
		}
	}
}
