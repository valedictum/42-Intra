/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/11/05 21:15:47 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node* find_element_with_rank(t_stack_node** stack, int target_rank)
{
    t_stack_node* current = *stack;

    while (current != NULL)
    {
        if (current->rank == target_rank)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void ps_update_positions(t_stack_node* stack)
{
    t_stack_node* current = stack;
    int position = 1;

    while (current != NULL)
    {
        current->position = position;
        current = current->next;
        position++;
    }
}

typedef struct s_chunk_node
{
    t_stack_node *element;
    struct s_chunk_node *next;
} t_chunk_node;


// CHUNK SORT - LINKED LIST APPROACH
void chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    int max_rank = get_max_rank(*stack_a);
    int chunk_size = max_rank / 5;
	int start_rank;
	int	end_rank;
	t_stack_node	*current;

	int	i;

	i = 0;
    while(i < 5)
	{
        start_rank = i * chunk_size + 1;
        end_rank = (i + 1) * chunk_size;
        current = *stack_a;
        t_chunk_node *chunk_head = NULL;
        t_chunk_node *chunk_tail = NULL;

        while (current != NULL)
		{
			if (is_sorted(*stack_a))
			{
				ft_printf("Stack A is already sorted, now to sort from Stack B back ONTO Stack A.\n");
				return;
			}
			/*
			// WORKING ON THIS PART
			if (*stack_a != NULL && (*stack_a)->next != NULL && (*stack_a)->rank > (*stack_a)->next->rank)
			{
				if (*stack_b != NULL && (*stack_b)->next != NULL && (*stack_b)->rank < (*stack_b)->next->rank)
				{
					ss(stack_a, stack_b, operation_count);
				}
			}
			*/
            if (current->rank >= start_rank && current->rank <= end_rank)
			{
                t_chunk_node *new_chunk_node = (t_chunk_node *)malloc(sizeof(t_chunk_node));
                new_chunk_node->element = current;
                new_chunk_node->next = NULL;

                if (chunk_tail == NULL)
				{
                    chunk_head = new_chunk_node;
                    chunk_tail = new_chunk_node;
                }
				else
				{
                    chunk_tail->next = new_chunk_node;
                    chunk_tail = new_chunk_node;
                }
            }
            current = current->next;
        }
        while (chunk_head != NULL)
		{
            t_stack_node *chunk_element = chunk_head->element;
			int	stack_size = ps_stack_size(*stack_a);

            if (chunk_element->position <= stack_size / 2)
			{
				while (*stack_a != chunk_element)
				{
					ra(stack_a, operation_count);
				}
			}
			else
			{
				while (*stack_a != chunk_element)
				{
					rra(stack_a, operation_count);
				}
			}
			pb(stack_a, stack_b, operation_count);
			ft_printf("Pushed %d to B (Rank %d)\n", chunk_element->value, chunk_element->rank);
            ft_printf("\n");
            ps_update_positions(*stack_a);
            ps_update_positions(*stack_b);
            print_stack_state("Stack A", *stack_a);
            print_stack_state("Stack B", *stack_b);
            t_chunk_node *temp = chunk_head;
            chunk_head = chunk_head->next;
            free(temp);
        }
		i++;
    }
    printf("\n");
    print_stack_state("Stack A", *stack_a);
    print_stack_state("Stack B", *stack_b);
}

// WORKING
void insertion_sort(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* target_element;
    int max_rank = ps_stack_size(*stack_b);
    int target_rank = 1;
    ft_printf("Stack B size: %d\n", max_rank);

    while (*stack_b != NULL && target_rank <= max_rank)
	{
        target_element = find_element_with_rank(stack_b, target_rank);
        t_stack_node* current = *stack_b;

        while (current != target_element) 
		{
            if (target_element->position <= ps_stack_size(*stack_b) / 2)
			{
                rb(stack_b, operation_count);
                current = *stack_b;
            }
			else
			{
                rrb(stack_b, operation_count);
                current = *stack_b;
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
	while (!ps_check_if_sorted(*stack_a))
	{
            ra(stack_a, operation_count);
    }
}
