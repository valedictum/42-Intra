/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 17:49:55 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_section_of_list(t_stack_node **head)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;
	long			temp;

	current_node = *head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		while (next_node != NULL)
		{
			if (current_node->value > next_node->value)
			{
				temp = current_node->value;
				current_node->value = next_node->value;
				next_node->value = temp;
			}
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
}

void	swap_stack_a_first_time(t_stack_node **stack_a,
	t_stack_node **copy_swap_stack_a)
{
	t_stack_node	*current_a;
	t_stack_node	*current_copy;

	current_a = *stack_a;
	current_copy = *copy_swap_stack_a;
	while (current_a != NULL)
	{
		current_copy->value = current_a->value;
		current_a = current_a->next;
		current_copy = current_copy->next;
	}
}

void	swap_stack_a_second_time(t_stack_node **stack_a,
	t_stack_node **copy_swap_stack_a)
{
	t_stack_node	*current_a;
	t_stack_node	*current_copy;
	t_stack_node	*current_copy_temp;
	int				index;

	current_a = *stack_a;
	current_copy = *copy_swap_stack_a;
	while (current_a != NULL)
	{
		current_copy_temp = *copy_swap_stack_a;
		index = 0;
		while (current_copy_temp != NULL)
		{
			if (current_copy_temp->value == current_copy->value)
			{
				current_a->value = index;
				break ;
			}
			current_copy_temp = current_copy_temp->next;
			index++;
		}
		current_a = current_a->next;
		current_copy = current_copy->next;
	}
}

void	swap_stack_a_third_time(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current_a;
	int				max_bits;
	int				max_num;
	int				bit_pos;

	max_bits = 0;
	max_num = 0;
	bit_pos = 0;
	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->value > max_num)
			max_num = current_a->value;
		current_a = current_a->next;
	}
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (bit_pos < max_bits)
	{
		current_a = *stack_a;
		while (current_a)
		{
			if (((current_a->value >> bit_pos) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
			current_a = current_a->next;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		bit_pos++;
	}
}

void	ps_sort_beyond_3_and_5_numbers(t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	t_stack_node	*copy;
	t_stack_node	*copy_swap_stack_a;

	copy = NULL;
	copy_swap_stack_a = NULL;
	copy_stack(stack_a, &copy);
	copy_stack(stack_a, &copy_swap_stack_a);
	sort_section_of_list(&copy);
	swap_stack_a_first_time(stack_a, &copy_swap_stack_a);
	swap_stack_a_second_time(stack_a, &copy_swap_stack_a);
	ps_free_stack(&copy);
	ps_free_stack(&copy_swap_stack_a);
	swap_stack_a_third_time(stack_a, stack_b);
}
