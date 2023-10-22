/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_3_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/22 21:03:06 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


/*
void merge(t_stack_node** stack_a, t_stack_node** stack_b, int* operation_count)
{
    while (*stack_a != NULL && *stack_b != NULL)
	{
        if ((*stack_a)->value < (*stack_b)->value)
		{
            pa(stack_a, stack_b, operation_count);
        }
		else
		{
            // Perform a rotation operation, either ra or rra, depending on the relative positions of the elements
            if ((*stack_b)->next == *stack_a)
                ra(stack_a, operation_count);
            else
                rra(stack_a, operation_count);
        }
    }
    // Move any remaining elements from stack_b to stack_a
    while (*stack_b != NULL)
	{
        pa(stack_b, stack_a, operation_count);
	}
}
*/

int ps_stack_rank_on_b(t_stack_node *stack, int value)
{
    int rank = 1;
    t_stack_node *current = stack;

    while (current != NULL) {
        if (current->value < value)
		{
            rank++;
        }
        current = current->next;
    }
    return (rank);
}



int ps_find_moves_to_top(t_stack_node* stack_b, int value)
{
    t_stack_node* current = stack_b;
    int moves = 0;

    while (current != NULL) {
        if (current->value == value) {
            return moves;
        }

        current = current->next;
        moves++;
    }

    return -1;  // Element not found in stack_a
}

/*
void merge(t_stack_node** stack_a, t_stack_node** stack_b, int* operation_count)
{
    while (*stack_b != NULL)
	{
        int rank_b;
		int	i;
		
		rank_b = ps_stack_rank_on_b(*stack_b, (*stack_b)->value);
        if (rank_b <= ps_stack_size(*stack_a) / 2)
		{
			i = 0;
            while (i < rank_b)
			{
                rb(stack_b, operation_count);
				ft_printf("-element rank LESS than or EQUAL TO half stack size\n");
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
				i++;
            }
        }
		else
		{
            i = 0;
			while (i < ps_stack_size(*stack_a) - rank_b + 1)
			{
                rrb(stack_b, operation_count);
				ft_printf("-element rank LESS stack size - rank + 1\n");
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
				i++;
            }
        }
        pa(stack_b, stack_a, operation_count);
		ft_printf("-merge push back onto A from B\n");
		ft_printf("Stack A (top to bottom):\n");
		if (*stack_a == NULL)
		ps_update_positions(*stack_a);
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
    }
}
*/

void merge(t_stack_node** stack_a, t_stack_node** stack_b, int* operation_count)
{
    int previous_value = INT_MAX;
	int i;
	int target_rank;
    
    while (*stack_b != NULL)
    {
		target_rank = (*stack_a)->rank + 1;
	 	if (*stack_a == NULL || (*stack_a)->rank == 1)
	 	{
            break;  // Exit the loop when stack_a is empty or its largest rank is 1
        }
        int moves_to_top = ps_find_moves_to_top(*stack_b, target_rank);
        if (moves_to_top <= ps_stack_size(*stack_a) / 2)
		{
            // Use ra if fewer moves are needed to bring the element to the top
			i = 0;
            while (i < moves_to_top)
			{
                rb(stack_b, operation_count);
				ft_printf("-rb takes LESS moves to top of B\n");
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
				i++;
            }
        }
		else
		{
            // Use rra if fewer moves are needed to bring the element to the top
			i = 0;
			while (i < ps_stack_size(*stack_a) - moves_to_top)
			{
                rrb(stack_b, operation_count);
				ft_printf("-reverse rb takes LESS moves to top of B\n");
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
				i++;
            }
        }
        if ((*stack_b)->rank == target_rank)
		{
            pa(stack_b, stack_a, operation_count);
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
            previous_value = (*stack_a)->value;
			target_rank++;
        }
    }
}

/*
void mergeSort(t_stack_node** stack_a, t_stack_node** stack_b, int* operation_count)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
        return; // Already sorted or empty
    }
    t_stack_node* left = NULL;
    t_stack_node* right = NULL;
    // Split the stack into two halves using pop operations (pb)
    int size = ps_stack_size(*stack_a);
    int half_size = size / 2;
    while (ps_stack_size(*stack_a) > half_size)
	{
        pb(stack_a, stack_b, operation_count);
		ft_printf("-merge sort division push from A onto B\n");
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
    }
    // Recursively sort the two halves
    left = *stack_a;  // Store the left half
    mergeSort(stack_a, stack_b, operation_count);
    right = *stack_a;  // Store the right half
    mergeSort(stack_a, stack_b, operation_count);
    // Merge the sorted halves
    merge(&left, &right, operation_count);	
    // Move the remaining elements from stack B to stack A
    while (*stack_b != NULL)
	{
        pa(stack_a, stack_b, operation_count);
		ft_printf("-after merge push from B back onto B\n");
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
    }
   int smallest_rank = 0;
	t_stack_node* current = *stack_a;
    while (current)
    {
        if (current->rank == smallest_rank)
        {
            break;
        }
        current = current->next;
    }
    int current_rank = 0;
    while (current_rank < size)
    {
        if (current_rank < half_size)
        {
            ra(stack_a, operation_count);
			ft_printf("-rotate ra to put smallest on top\n");
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
        }
        else
        {
            rra(stack_a, operation_count);
			ft_printf("-reverse rotate rra to put smallest on top\n");
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
        }
        current_rank++;
    }
}
*/

/*
void quicksort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL)
    {
        return;
    }

    int pivot = (*stack_a)->value;
    t_stack_node *current = (*stack_a)->next;
    t_stack_node *next;

    int pushed_to_b = 0; // Flag to track if elements were pushed to Stack B

    while (current != NULL)
    {
        next = current->next;
        if (current->value < pivot)
        {
            pb(stack_a, stack_b, operation_count); // Push smaller elements to Stack B
            pushed_to_b = 1;
        }
        else
        {
            pa(stack_b, stack_a, operation_count); // Push greater elements to Stack A
        }
        current = next;
    }

    // Recursively quicksort the remaining elements on stack_b
    quicksort(stack_b, stack_a, operation_count);

    // If elements were pushed to stack_b and stack_a is empty, move elements back from stack_b to stack_a
    if (pushed_to_b && *stack_a == NULL)
    {
        while (*stack_b != NULL)
        {
            pa(stack_b, stack_a, operation_count);
        }
    }
*/


//WORKING BUT IN PROGRESS

void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
	t_stack_node* next = current->next;
	
    int target_rank = ps_stack_size(*stack_a);
	
    while ((current != NULL) && (current->next != NULL))
    {
        while (current != target_element)
        {
            target_element = find_element_with_rank(stack_a, target_rank);
			ft_printf("Target is %d, current is %d\n", target_element->value, current->value);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b, operation_count);
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
			else if (target_rank == next->rank)
            {
                sa(stack_a, operation_count);
				current = *stack_a;
				pb(stack_a, stack_b, operation_count);
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
                ra(stack_a, operation_count);
            }
            else
            {
                rra(stack_a, operation_count);
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b, operation_count);
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}

/*
//DON'T TOUCH IT WORKS!//
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
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
                pb(stack_a, stack_b, operation_count);
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
                ra(stack_a, operation_count);
            }
            else
            {
                rra(stack_a, operation_count);
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b, operation_count);
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}
*/


/*
// REVERSES AND WORKING //

void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
    int target_rank = 1;

    while ((current != NULL) && (current->next != NULL))
    {
        while (current != target_element)
        {
            target_element = find_element_with_rank(stack_a, target_rank);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b, operation_count);
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
                ra(stack_a, operation_count);
				if (*stack_b != NULL && (*stack_b)->rank == current->rank + 1)
				{
					ra(stack_a, operation_count);
					pa(stack_a, stack_b, operation_count);
					ra(stack_a, operation_count);
				}
            }
            else
            {
                rra(stack_a, operation_count);
				if (*stack_b != NULL && (*stack_b)->rank == current->rank + 1)
				{
					ra(stack_a, operation_count);
					pa(stack_a, stack_b, operation_count);
					ra(stack_a, operation_count);
				}
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b, operation_count);
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}
*/
