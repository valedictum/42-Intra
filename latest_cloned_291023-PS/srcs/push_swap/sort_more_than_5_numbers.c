/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/10/29 20:32:01 by atang            ###   ########.fr       */
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
void chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank;
    start_rank = 1;
    ft_printf("# of elements: %d\n", max_rank);
    ft_printf("Chunk size: %d\n", chunk_size);

    while (start_rank <= max_rank)
    {
        // Calculate the end rank for the current chunk
        end_rank = start_rank + chunk_size - 1;

        // Find elements within the current chunk
        current = *stack_a;

        // Create an array to store the elements within the chunk
        t_stack_node *chunk_elements[max_rank];

        int num_elements = 0;

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
                chunk_elements[num_elements++] = current;
            }
            current = current->next;
        }

       // Sort the elements within the chunk using ra and rra
	for (int i = num_elements - 1; i >= 0; i--)  // Change the loop to start from the end
	{
		while (*stack_a != chunk_elements[i])
		{
			if (chunk_elements[i]->position <= ps_stack_size(*stack_a) / 2)
			{
				ra(stack_a, operation_count);
			}
			else
			{
				rra(stack_a, operation_count);
			}
		}

		// Push the element to stack B
		pb(stack_a, stack_b, operation_count);
		ft_printf("Element %d (Rank %d) pushed to B\n", chunk_elements[i]->value, chunk_elements[i]->rank);
	}


        // Update the start_rank for the next chunk
        start_rank = end_rank + 1;
    }

    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}
*/

/*
void chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank;
    start_rank = 1;
    ft_printf("# of elements: %d\n", max_rank);
    ft_printf("Chunk size: %d\n", chunk_size);

    while (start_rank <= max_rank)
    {
        // Calculate the end rank for the current chunk
        end_rank = start_rank + chunk_size - 1;

        // Find elements within the current chunk
        current = *stack_a;

        // Create an array to store the elements within the chunk
        t_stack_node *chunk_elements[max_rank];

        int num_elements = 0;

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
                chunk_elements[num_elements++] = current;
            }
            current = current->next;
        }

        // Sort the elements within the chunk using ra and rra
        for (int i = 0; i < num_elements; i++)
        {
            while (*stack_a != chunk_elements[i])
            {
                if (chunk_elements[i]->position <= ps_stack_size(*stack_a) / 2)
                {
                    ra(stack_a, operation_count);
                }
                else
                {
                    rra(stack_a, operation_count);
                }
            }

            // Push the element to stack B
            pb(stack_a, stack_b, operation_count);
            ft_printf("Element %d (Rank %d) pushed to B\n", chunk_elements[i]->value, chunk_elements[i]->rank);
        }

        // Update the start_rank for the next chunk
        start_rank = end_rank + 1;
    }

    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}
*/

/* void chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
	int	i;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank / 4;
    start_rank = max_rank;
    ft_printf("# of elements: %d\n", max_rank);
    ft_printf("Chunk size: %d\n", chunk_size);

    while (start_rank >= 1)
    {
        // Calculate the end rank for the current chunk
        end_rank = start_rank - chunk_size + 1;

        // Find elements within the current chunk
        current = *stack_a;

        // Create an array to store the elements within the chunk
        t_stack_node *chunk_elements[max_rank];

        int num_elements = 0;

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
                chunk_elements[num_elements++] = current;
            }
            current = current->next;
        }

        // Sort the elements within the chunk using ra
        for (int i = 0; i < num_elements; i++)
        {
            while (*stack_a != chunk_elements[i])
            {
                if (chunk_elements[i]->position <= ps_stack_size(*stack_a) / 2)
                {
                    ra(stack_a, operation_count);
                }
                else
                {
                    rra(stack_a, operation_count);
                }
            }
        }
		i = num_elements -1;
        // Push the elements to stack B (smaller ranks first)
        while (i >= 0)
        {
            pb(stack_a, stack_b, operation_count);
            ft_printf("Element %d (Rank %d) pushed to B\n", chunk_elements[i]->value, chunk_elements[i]->rank);
			i++;
        }
        // Update the start_rank for the next chunk
        start_rank = end_rank - 1;
    }
    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}
 */

void chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank;
    start_rank = 1;
    ft_printf("# of elements: %d\n", max_rank);
    ft_printf("Chunk size: %d\n", chunk_size);

    while (start_rank <= max_rank)
    {
        // Calculate the end rank for the current chunk
        end_rank = start_rank + chunk_size - 1;

        // Find elements within the current chunk
        current = *stack_a;

        // Create an array to store the elements within the chunk
        t_stack_node *chunk_elements[max_rank];

        int num_elements = 0;

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
                chunk_elements[num_elements++] = current;
            }
            current = current->next;
        }

        // Sort the elements within the chunk using ra and rra
        for (int i = 0; i < num_elements; i++)
        {
            while (*stack_a != chunk_elements[i])
            {
                if (chunk_elements[i]->position <= ps_stack_size(*stack_a) / 2)
                {
                    ra(stack_a, operation_count);
                }
                else
                {
                    rra(stack_a, operation_count);
                }
            }

            // Push the element to stack B
            pb(stack_a, stack_b, operation_count);
            ft_printf("Element %d (Rank %d) pushed to B\n", chunk_elements[i]->value, chunk_elements[i]->rank);
        }

        // Update the start_rank for the next chunk
        start_rank = end_rank + 1;
    }

    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}


/*
// WORKS TO PUSH TO BUT ONLY FOR ONE ELEMENT IN A CHUNK

void chunk_of_fifths(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank / 4;
    start_rank = 1;
    ft_printf("# of elements: %d\n", max_rank);
    ft_printf("Chunk size: %d\n", chunk_size);

    while (start_rank <= max_rank)
    {
        end_rank = start_rank + chunk_size - 1;
        current = *stack_a;
        t_stack_node *last_element = NULL; // Track the last element in the chunk

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
                if (current->position <= ps_stack_size(*stack_a) / 2)
                {
                    while (*stack_a != current)
                        ra(stack_a, operation_count);
                }
                else
                {
                    while (*stack_a != current)
                        rra(stack_a, operation_count);
                }

                if (last_element != NULL)
                {
                    pb(stack_a, stack_b, operation_count);
                    ft_printf("Element %d in chunk pushed to B (Rank %d)\n", last_element->value, last_element->rank);
                }
                last_element = current;
            }
            current = current->next;
        }

        if (last_element != NULL)
        {
            pb(stack_a, stack_b, operation_count);
            ft_printf("Element %d in chunk pushed to B (Rank %d)\n", last_element->value, last_element->rank);
        }

        start_rank = end_rank + 1;
    }

    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}
*/

/*
// ONLY DOES HALF THE ELEMENTS OF CHUNK
void chunk_of_fifths(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank;
    int chunk_size;
    int start_rank;
    int end_rank;
    t_stack_node *current;

    max_rank = get_max_rank(*stack_a);
    chunk_size = max_rank / 4;
    start_rank = 1;
	ft_printf("# of elements: %d\n", max_rank);
	ft_printf("Chunk size: %d\n", chunk_size);
 while (start_rank <= max_rank)
    {
        end_rank = start_rank + chunk_size - 1;
        current = *stack_a;

        while (current != NULL)
        {
            if (current->rank >= start_rank && current->rank <= end_rank)
            {
				if (current->position <= ps_stack_size(*stack_a) / 2)
                {
                    while (*stack_a != current)
                        ra(stack_a, operation_count);
                }
                else
                {
                    while (*stack_a != current)
                        rra(stack_a, operation_count);
                }
				if (*stack_a == current)
				{
					pb(stack_a, stack_b, operation_count);
                	ft_printf("Element %d in chunk pushed to B (Rank %d)\n", current->value, current->rank);
				}
            }
            current = current->next;
		}
        start_rank = end_rank + 1;
    }
    ft_printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}
*/


/*
static void rotate_until_smallest_on_top(t_stack_node** stack_a, int *operation_count)
{
    t_stack_node* current = *stack_a;
    t_stack_node* smallest = current;
    int rotations = 0;

    // Find the smallest element in Stack A and calculate the number of rotations
    while (current != NULL) {
        if (current->value < smallest->value) {
            smallest = current;
            rotations = ps_stack_size(*stack_a) - current->position;
        }
        current = current->next;
    }

    // Perform the necessary rotations
    while (rotations > 0)
	{
        ra(stack_a, operation_count);
        rotations--;
    }
}
*/


// WORKS
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* target_element;
	int	max_rank = ps_stack_size(*stack_b);
    int target_rank = 1;
    ft_printf("Stack B size: %d\n", target_rank);

    while (*stack_b != NULL && target_rank <= max_rank)
    {
        target_element = find_element_with_rank(stack_b, target_rank);
        t_stack_node* current = *stack_b;

        while (current != target_element)
        {
            if (target_element->position <= ps_stack_size(*stack_b) / 2)
            {
                rb(stack_b, operation_count);
                current = *stack_b;  // Update the current pointer
            }
            else
            {
                rrb(stack_b, operation_count);
                current = *stack_b;  // Update the current pointer
            }
        }
        if (*stack_b != NULL)
        {
            ft_printf("\n");
            pa(stack_a, stack_b, operation_count);
            ft_printf("Pushed %d to A (Rank %d)\n", target_element->value, target_element->rank);
            ft_printf("\n");
            ps_update_positions(*stack_a);
            ps_update_positions(*stack_b);
            print_stack_state("Stack A", *stack_a);
            print_stack_state("Stack B", *stack_b);
            target_rank++;
        }
    }
}


/*
// REVERSE BUT WORKING 
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* target_element;
    int target_rank = ps_stack_size(*stack_b);
    ft_printf("Stack B size: %d\n", target_rank);

    while (*stack_b != NULL)
    {
        target_element = find_element_with_rank(stack_b, target_rank);
        t_stack_node* current = *stack_b;

		while (current != target_element)
		{
			if (target_element->position <= ps_stack_size(*stack_b) / 2)
			{
				rb(stack_b, operation_count);  // Use rb instead of rrb
				current = *stack_b;  // Update the current pointer
			}
			else
			{
				rrb(stack_b, operation_count);
				current = *stack_b;  // Update the current pointer
			}
		}
        if (*stack_b != NULL)
		{  // Check if stack B is not empty before accessing it
            ft_printf("\n");
            pa(stack_a, stack_b, operation_count);
            ft_printf("Pushed %d to A (Rank %d)\n", target_element->value, target_element->rank);
			ft_printf("\n");
			ps_update_positions(*stack_a);
            ps_update_positions(*stack_b);
   			print_stack_state("Stack A", *stack_a);
    		print_stack_state("Stack B", *stack_b);
            target_rank--;
        }
    }
}
*/


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
