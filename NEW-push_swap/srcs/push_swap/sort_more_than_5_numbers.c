/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/15 19:48:37 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	ps_put_min_on_top(t_stack_node	**stack_a)
{
	t_stack_node	*min_node;

	min_node = ps_min_node(*stack_a);
	while (*stack_a != min_node)
	{
		if (min_node->upper_half)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
*/

int	ps_stack_peek(t_stack_node *stack, int index)
{
	t_stack_node	*current;
	int				i;

	if (index < 0 || stack == NULL)
	{
		return (-1);
	}
    i = 0;
    current = stack;
    while (i < index && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
        return (-1);
    return (current->value);
}


void ps_compare_and_move_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int element_to_move)
{
    int		a_size;
	int		b_size;
	char	best_operation;
	int		best_move_count;
	int		i;
	int		current_element_b;
	int 	move_count_pb;
	int 	move_count_ra; 
	int 	move_count_rra;
	t_stack_node	*current;

	current = *stack_a;
	a_size = ps_stack_size(*stack_a);
	b_size = ps_stack_size(*stack_b);
	best_operation = 'N';
    best_move_count = a_size + b_size;
	i = 0;
    while (i < b_size)
	{
        current_element_b = ps_stack_peek(*stack_b, i);
        move_count_pb = a_size + b_size + 1;
        move_count_ra = i + 1;
        move_count_rra = b_size - i + 1;

        if (element_to_move < current_element_b)
		{
            move_count_pb = a_size + b_size;
        }
	   else if (element_to_move > current_element_b)
        {
            sa(stack_a);
            rra(stack_a);
        }
        if (move_count_pb < best_move_count)
		{
            best_operation = 'P';
            best_move_count = move_count_pb;
        }
        if (move_count_ra < best_move_count)
		{
            best_operation = 'R';
            best_move_count = move_count_ra;
        }
        if (move_count_rra < best_move_count)
		{
            best_operation = 'r';
            best_move_count = move_count_rra;
        }
		i++;
    }
    if (best_operation == 'P')
	{
        pb(stack_a, stack_b);
		ft_printf("* Best operation is pb\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A (top to bottom):\n");
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):n");
		ps_print_stack(*stack_b);
		ft_printf("\n");
    } 
	else if (best_operation == 'R')
	{
        ra(stack_a);
		ft_printf("* Best operation is ra\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A (top to bottom):\n");
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		ps_print_stack(*stack_b);
		ft_printf("\n");
    } 
	else if (best_operation == 'r')
	{
        rra(stack_a);
		ft_printf("* Best operation is rra\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A (top to bottom):\n");
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		ps_print_stack(*stack_b);
		ft_printf("\n");
    }
}

/*
void insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *current = *stack_a;
    t_stack_node *next;

    while (current != NULL)
    {
        next = current->next;
        
        if (ps_stack_size(*stack_b) == 0)
        {
            pb(stack_a, stack_b);
        }
        else
        {
            while (ps_stack_size(*stack_b) > 0 && current->value < ps_stack_peek(*stack_b, 0))
            {
                ps_compare_and_move_to_b(stack_a, stack_b, current->value);
            }
            pb(stack_a, stack_b);
        }
        
        current = next;
    }
    if (ps_check_if_sorted(*stack_a))
	{
        return;
    }
	ps_put_min_on_top(stack_a);
}
*/

//CURRENT WORKING
/*
void insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *sorted = NULL;
    t_stack_node *current = *stack_a;
    t_stack_node *next;

	if (!ps_check_if_sorted(*stack_a))
	{
		sa(stack_a);
    	pb(stack_a, stack_b);
		while (current != NULL)
		{
			next = current->next;
			if (sorted == NULL)
			{
				pb(stack_a, stack_b);
				sorted = current;
				ft_printf("* Sorted is NULL\n");
				ft_printf("Current: %d\n", current->value);
				if (sorted != NULL)
					printf("Sorted: %ld\n", sorted->value);
				ft_printf("Stack A (top to bottom):\n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B (top to bottom):\n");
				ps_print_stack(*stack_b);
				ft_printf("\n");
			}
			else if (current->value < sorted->value)
			{
				ps_compare_and_move_to_b(stack_a, stack_b, current->value);
				pb(stack_a, stack_b);
				sorted = current;
				ft_printf("* Current LESS than Sorted\n");
				ft_printf("Current: %d\n", current->value);
				if (sorted != NULL)
					printf("Sorted: %ld\n", sorted->value);
				ft_printf("Stack A (top to bottom):\n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B (top to bottom):\n");
				ps_print_stack(*stack_b);
				ft_printf("\n");
			}
			else if (current->value > sorted->value)
			{
				while (ps_stack_size(*stack_b) > 0 && current->value > ps_stack_peek(*stack_b, 0))
				{
					ps_compare_and_move_to_b(stack_a, stack_b, current->value);
					pb(stack_a, stack_b);
					sorted = current;
					ft_printf("* Current GREATER than Sorted\n");
					ft_printf("Current: %d\n", current->value);
					if (sorted != NULL)
						printf("Sorted: %ld\n", sorted->value);
					ft_printf("Stack A (top to bottom):\n");
					ps_print_stack(*stack_a);
					ft_printf("Stack B (top to bottom):\n");
					ps_print_stack(*stack_b);
					ft_printf("\n");
				}
			}
			if (next != NULL)
			{
				current = next;
			}
				else
			{
				break;
			}
		}
		while (*stack_b != NULL)
		{
			pa(stack_a, stack_b);
			ft_printf("* Number pushed from B onto A (while there are still elements on B)\n");
			if (*stack_a != NULL) {
				current = *stack_a;
				ft_printf("Current: %d\n", current->value);
			}
			if (sorted != NULL)
				printf("Sorted: %ld\n", sorted->value);
			ft_printf("Stack A (top to bottom):\n");
			ps_print_stack(*stack_a);
			ft_printf("Stack B (top to bottom):\n");
			ps_print_stack(*stack_b);
			ft_printf("\n");
		}
		ps_put_min_on_top(stack_a);
	}
}
*/

//NEWEST VERSION
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
					ft_printf("Current: %d\n", current->value);
					if (sorted != NULL)
						ft_printf("Sorted: %d\n", sorted->value);
					ft_printf("Stack A (top to bottom):\n");
					ps_print_stack(*stack_a);
					ft_printf("Stack B (top to bottom):\n");
					ft_printf("\n");
					ps_print_stack(*stack_b);
				}
				else
				{
					rra(stack_a);
					pb(stack_a, stack_b);
					ft_printf("Current: %d\n", current->value);
					if (sorted != NULL)
						ft_printf("Sorted: %d\n", sorted->value);
					ft_printf("Stack A (top to bottom):\n");
					ps_print_stack(*stack_a);
					ft_printf("Stack B (top to bottom):\n");
					ft_printf("\n");
					ps_print_stack(*stack_b);
				}
			}
			else if (sorted == NULL)
			{
				if (current->value > next->value)
					sa(stack_a);
				pb(stack_a, stack_b);
				ft_printf("Current: %d\n", current->value);
				if (sorted != NULL)
					ft_printf("Sorted: %d\n", sorted->value);
				ft_printf("Stack A (top to bottom):\n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B (top to bottom):\n");
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
				ft_printf("Current: %d\n", current->value);
				if (sorted != NULL)
					ft_printf("Sorted: %d\n", sorted->value);
				ft_printf("Stack A (top to bottom):\n");
				ps_print_stack(*stack_a);
				ft_printf("Stack B (top to bottom):\n");
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
		if (sorted != NULL)
			ft_printf("Sorted: %d\n", sorted->value);
		ft_printf("Stack A (top to bottom):\n");
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		ps_print_stack(*stack_b);
		ft_printf("\n");
	}
}


/*
//THUGGONAUT VERSION
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value 
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = ps_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
*/

/*
// SECOND NEWEST VERSION //
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
