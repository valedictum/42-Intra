/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2023/09/24 18:56:57 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct stack_node
{
	int					value;
	struct stack_node	*next;
}	t_stack_node;

void			print_stack(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			sort_two_elements(t_stack_node **stack_a);
void			sort_three_elements(t_stack_node **stack_a);
void			sort_five_elements(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			free_linked_list(t_stack_node **head);
int				stack_size(t_stack_node *stack);
void			merge_sort(t_stack_node **stack_a);
t_stack_node	*sorted_merge(t_stack_node *stack_a, t_stack_node *stack_b);
void			find_middle(t_stack_node *stack_a, t_stack_node **front_ref,
					t_stack_node **back_ref);
void			push(t_stack_node **head_ref, int new_data);
/* void			merge(t_stack_node **stack_a, t_stack_node **stack_b,
					int left_size, int right_size);
void			merge_sort(t_stack_node **stack_a, t_stack_node **stack_b); */
//swap_operations.c
void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
//push_operations.c
void			pa(t_stack_node	**stack_a, t_stack_node **stack_b);
void			pb(t_stack_node	**stack_b, t_stack_node **stack_a);
//rotate_operations.c
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
//reverse_rotate_operations.c
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
//push_swap.c
int				ps_atoi(const char *str);
t_stack_node	*read_values_and_push_onto_stack_a(int argc, char *argv[]);

#endif