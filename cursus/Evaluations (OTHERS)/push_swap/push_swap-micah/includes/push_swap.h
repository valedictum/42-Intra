/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:25:16 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:25:19 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libpush_swap.h"
# include "push_swap_structs.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Arguments
void		parse_argument(char *arg, int **numbers, int *size);
void		parse_multi_arguments(char **arg, int **numbers, int *size);
int			int_len(char **pika);
bool		check_unique(int *numbers, int len);
bool		check_alpha(char **arg);
bool		is_it_sorted(t_stack *stack);

// Algorithms
void		sort_three(t_stack *stack);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		cost_sort(t_stack *stack_a, t_stack *stack_b);
void		some_internet_sort(t_stack *stack_a, t_stack *stack_b);

// Initialisations
int			amount_of_numbers(char **arg);
void		initialise_stacks(t_stack **stack_a, t_stack **stack_b,
				int *numbers, int size);
void		initialise_new_values(t_stack *stack);
void		set_numbers(t_stack *stack, int *numbers);

// Operations
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse(t_stack *stack);
void		push(t_stack *stack_from, t_stack *stack_to);
void		run_operation(t_stack *stack_a, t_stack *stack_b, int op);

// Stack utilities
void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		revert_to_head(t_stack *stack);
void		refresh_index(t_stack *stack);
void		reset_stack(t_stack *stack);
int			find_stack_size(t_stack *stack);
int			find_min_int(t_stack *stack);
int			find_max_int(t_stack *stack);
void		t_set_targets_a(t_stack *stack_a, t_stack *stack_b);
void		t_set_targets_b(t_stack *stack_a, t_stack *stack_b);
void		reset_min_max(t_stack *stack_a, t_stack *stack_b);
void		reset_a(t_stack *stack_a, t_stack *stack_b);
void		reset_b(t_stack *stack_a, t_stack *stack_b);

// Search functions
void		bring_to_top(t_stack *stack, int value);
void		bring_to_top_b(t_stack *stack, int value);
void		bring_to_top_both(t_stack *stack_a, t_stack *stack_b,
				t_number *target, t_number *candidate);
void		bring_to_top_both_b(t_stack *stack_a, t_stack *stack_b,
				t_number *target, t_number *candidate);
t_number	*find_node_by_index(t_stack *stack, int index);
t_number	*find_node_by_value(t_stack *stack, int value);
t_number	*find_cheapest(t_stack *stack);
t_number	*find_target_node_b(t_stack *stack, t_number *number);
t_number	*find_target_node_a(t_stack *stack, t_number *number);

// Calculations
int			calculate_moves_to_top(t_stack *stack, t_number *value);
void		calculate_costs(t_stack *stack_a, t_stack *stack_b);
void		calculate_costs_b(t_stack *stack_a, t_stack *stack_b);
void		cost_move_b_to_a(t_stack *stack_a, t_stack *stack_b);
void		cost_reset_b(t_stack *stack_a, t_stack *stack_b);
int			calculate_a(t_stack *stack);
int			calculate_x(t_stack *stack, int a);

// Printers
void		print_operation(int op);
void		print_error(void);

#endif
