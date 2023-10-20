/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_3_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/20 18:52:12 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			pb(stack_a, stack_b);
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
		pb(stack_a, stack_b);
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
		pb(stack_a, stack_b);
		ft_printf("* Best operation is rra\n");
		ft_printf("Current: %d\n", current->value);
		ft_printf("Stack A (top to bottom):\n");
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		ps_print_stack(*stack_b);
		ft_printf("\n");
    }
}

bool is_sorted_ascending(t_stack_node* stack_a)
{
    t_stack_node* current = stack_a;
    while (current != NULL && current->next != NULL)
    {
        if (current->rank > current->next->rank)
        {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool is_sorted_descending(t_stack_node* stack)
{
    while (stack != NULL && stack->next != NULL) {
        if (stack->value < stack->next->value) {
            return false;
        }
        stack = stack->next;
    }
    return true;
}

bool is_in_top_half(int element_position, int stack_size)
{
    return element_position <= (stack_size / 2);
}

t_stack_node* find_element_with_rank(t_stack_node** stack, int target_rank)
{
    t_stack_node* current = *stack;

    while (current != NULL)
    {
        if (current->rank == target_rank)
        {
            return current; // Found the element with the target rank
        }
        current = current->next;
    }
    // Return NULL if the element with the target rank is not found
    return NULL;
}

int get_target_position(t_stack_node* stack, int target_rank)
{
    t_stack_node* current = stack;
    while (current != NULL)
    {
        if (current->rank == target_rank)
        {
            return current->position;
        }
        current = current->next;
    }
    return -1; // Target not found
}

void ps_update_positions(t_stack_node* stack)
{
    t_stack_node* current = stack;
    int position = 1; // Initialize the position to 1 for the top element

    while (current != NULL)
    {
        current->position = position;
        current = current->next;
        position++;
    }
}


void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
    int target_rank = ps_stack_size(*stack_a);

    while ((current != NULL) && (current->next != NULL))
    {
        while (current != target_element)
        {
            target_element = find_element_with_rank(stack_a, target_rank);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b);
                ft_printf("Target at top of A - Pushed %d to B (Rank %d)\n", target_element->value, target_element->rank);
                ps_update_positions(*stack_a);
                ps_update_positions(*stack_b);
                ft_printf("Stack A (top to bottom):\n");
                if (*stack_a == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_a);
                ft_printf("Stack B (top to bottom):\n");
                if (*stack_b == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_b);
                ft_printf("\n");
                target_rank--;
                current = *stack_a;
                break;
            }
            else if (current->position <= ps_stack_size(*stack_a) / 2)
            {
                ra(stack_a);
            }
            else
            {
                rra(stack_a);
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b);
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}

/*
// DESCENDING BUT WORKS!!! //
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
    int target_rank = 1;

    while ((current != NULL) && (current-> next != NULL))
    {
        while (current != target_element)
        {
            target_element = find_element_with_rank(stack_a, target_rank);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b);
				ft_printf("Target at top of A - Pushed %d to B (Rank %d)\n", target_element->value, target_element->rank);
                ps_update_positions(*stack_a);
                ps_update_positions(*stack_b);
                ft_printf("Stack A (top to bottom):\n");
                if (*stack_a == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_a);
                ft_printf("Stack B (top to bottom):\n");
                if (*stack_b == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_b);
                ft_printf("\n");
                target_rank++;
                current = *stack_a;
                break;
            }
            else if (current->position <= ps_stack_size(*stack_a) / 2)
            {
                ra(stack_a);
            }
            else
            {
                rra(stack_a);
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b);
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}
*/

// WORKING BUT JUST NOT SORTING //
/*
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
    int target_rank = 1;

    while (current != NULL)
    {
        while (current->rank != target_rank)
        {
			target_element = find_element_with_rank(stack_a, target_rank);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b);
				ft_printf("Target at top of A - Pushed %d to B (Rank %d)\n", current->value, current->rank);
				ps_update_positions(*stack_a);
				ps_update_positions(*stack_b);
				ft_printf("Stack A (top to bottom):\n");
				if (*stack_a == NULL)
				{
					ft_printf("--Empty--\n");
				}
				ps_print_stack(*stack_a);
				ft_printf("Stack B (top to bottom):\n");
				if (*stack_b == NULL)
				{
					ft_printf("--Empty--\n");
				}
				ps_print_stack(*stack_b);
				ft_printf("\n");
                target_rank++;
                current = *stack_a;
				current = current->next;
                break;
            }
            else if (current->position <= ps_stack_size(*stack_a) / 2)
            {
                ra(stack_a);
            }
            else
            {
                rra(stack_a);
            }
		}
    }
	if (!is_sorted_ascending(*stack_b))
    {
        rb(stack_b);
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b);
		ft_printf("Pushing element from B back onto A\n");
		ft_printf("\n");
    }
}
*/

/*
// BEFORE RANK VERSION //

void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b)
{
    t_stack_node* current = *stack_a;

    while (current != NULL)
    {
        while (*stack_b != NULL)
        {
            pa(stack_a, stack_b);
            ft_printf("pa\n");
        }
        if (current->position != 1)
        {
            if (current->position <= ps_stack_size(*stack_a) / 2)
            {
                ra(stack_a);
            }
            else
            {
                rra(stack_a);
            }
        }
        else
        {
            pb(stack_a, stack_b);
		}
        ps_update_positions(*stack_a);
        ps_update_positions(*stack_b);
		ft_printf("Stack A (top to bottom):\n");
		if (*stack_a == NULL)
        {
            ft_printf("--Empty--\n");
        }
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		if (*stack_b == NULL)
        {
            ft_printf("--Empty--\n");
        }
		ps_print_stack(*stack_b);
		current = current->next;
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b);
		ft_printf("Stack A (top to bottom):\n");
		if (*stack_a == NULL)
        {
            ft_printf("--Empty--\n");
        }
		ps_print_stack(*stack_a);
		ft_printf("Stack B (top to bottom):\n");
		if (*stack_b == NULL)
        {
            ft_printf("--Empty--\n");
        }
		ps_print_stack(*stack_b);
	}
}
*/

/*
// FRIDAY 20/10/23 BEGINNING VERSION //
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
*/