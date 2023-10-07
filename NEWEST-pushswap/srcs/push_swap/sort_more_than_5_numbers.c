/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/07 18:25:00 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*sorted;
	t_stack_node	*next;
	t_stack_node	*current;

	sorted = NULL;
	current = *stack_a;
	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || current->value < sorted->value)
		{
			if (sorted != NULL && current->value < sorted->value && current->value < next->value)
			{
				if (next->value > sorted->value)
				{
					sa(stack_a);
					pb(stack_a, stack_b);
					ft_printf("(If sorted not null AND sorted > current AND next > current) AND (next GREATER than sorted)");
					ft_printf("Current: %d\n", current->value);
					ft_printf("Stack A(from top): \n");
					ps_print_stack(*stack_a);
					ft_printf("Stack B(from top): \n");
					ft_printf("\n");
					ps_print_stack(*stack_b);
				}
				else
				{
					rra(stack_a);
					pb(stack_a, stack_b);
					ft_printf("(If sorted not null AND sorted > current AND next > current) AND (next LESS than sorted)");
					ft_printf("Current: %d\n", current->value);
					ft_printf("Stack A(from top): \n");
					ps_print_stack(*stack_a);
					ft_printf("Stack B(from top): \n");
					ft_printf("\n");
					ps_print_stack(*stack_b);
				}
			}
			else
			{
				pb(stack_a, stack_b);
				ft_printf("* Number pushed from A onto B (Sorted IS null OR Sorted GREATER than Current)\n");
				ft_printf("Current: %d\n", current->value);
				ft_printf("Stack A(from top): \n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B(from top): \n");
				ps_print_stack(*stack_b);
				ft_printf("\n");
			}
			sorted = *stack_b;
		}
		else
		{
			while (sorted != NULL && sorted->value < current->value)
			{
				pb(stack_a, stack_b);
				ft_printf("* Number pushed from A onto B (Sorted ISN'T null OR Current is GREATER than Sorted)\n");
				ft_printf("Current: %d\n", current->value);
				ft_printf("Stack A(from top): \n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B(from top): \n");
				ps_print_stack(*stack_b);
				ft_printf("\n");
				sorted = *stack_b;
				if (sorted != NULL && current->value > sorted->value)
					break ;
			}
		}
		current = next;
		if (current == NULL || current->next == NULL)
			break ;
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		ft_printf("* Number pushed from B onto A (while there are still elements on B)\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A(from top): ");
		ps_print_stack(*stack_a);
		ft_printf("Stack B(from top): ");
		ps_print_stack(*stack_b);
		ft_printf("\n");
	}
}

/*
// NEWEST VERSION //
void insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*sorted;
	t_stack_node	*next;
	t_stack_node	*current;
	int				num_elements;

	sorted = NULL;
	current = *stack_a;
	num_elements = 0;
	while (current != NULL)
	{
		num_elements++;
		current = current->next;
	}
	current = *stack_a;
	while (num_elements > 1)
	{

		next = current->next;
		if (sorted == NULL || current->value < sorted->value)
		{
			pb(stack_a, stack_b);
			ft_printf("* Number pushed from A onto B ()\n");
			ft_printf("Current: %d\n", current->value);
			ft_printf("Stack A(from top): \n");
			ps_print_stack(*stack_a);
			ft_printf("Stack B(from top): \n");
			ps_print_stack(*stack_b);
			ft_printf("\n");
			sorted = *stack_b;
		}
		else
		{
			while (sorted != NULL && current->value > sorted->value)
			{
				ra(stack_a);
				ft_printf("* Rotate A ()\n");
				ft_printf("Current: %d\n", current->value);
				ft_printf("Stack A(from top): \n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B(from top): \n");
				ps_print_stack(*stack_b);
				ft_printf("\n");
				sorted = *stack_a;
			}
			pb(stack_a, stack_b);
			ft_printf("* Number pushed from A onto B ()\n");
			ft_printf("Current: %d\n", current->value);
			ft_printf("Stack A(from top): \n");
			ps_print_stack(*stack_a);
			ft_printf("Stack B(from top): \n");
			ps_print_stack(*stack_b);
			ft_printf("\n");
			sorted = *stack_b;
		}
		current = next;
		num_elements--;
		if (num_elements <= 1)
			break ;
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		ft_printf("* Number pushed from B onto A (while there are still elements on B)\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A(from top): ");
		ps_print_stack(*stack_a);
		ft_printf("Stack B(from top): ");
		ps_print_stack(*stack_b);
		ft_printf("\n");
	}
}
*/

/* 
// PREVIOUS VERSION //
void	insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*sorted;
	t_stack_node	*next;
	t_stack_node	*current;

	sorted = NULL;
	current = *stack_a;
	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || sorted->value > current->value)
		{
			pb(stack_a, stack_b);
			sorted = *stack_a;
		}
		else
		{
			while (*stack_a != sorted)
			{
				if ((current->value) > sorted->value) 
				{
					sa(stack_a);
					while (*stack_a != sorted)
						rra(stack_a);
					break ;
				}
			}
			ra(stack_a);
			sorted = *stack_a;
		}
		current = next;
	}
}
 */

/* 
// PROSSI VERSION //
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

void	ps_sort_beyond_5_numbers(t_stack_node **stack_a,
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
*/
