/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2023/10/20 16:09:40 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h> 
# include "../../libs/printf/ft_printf.h"


typedef struct stack_node
{
	long				value;
	int					rank;
	int					position;
	bool				upper_half;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_stack_node;

/* 
bool				movement_cost;
bool				cheapest;
struct stack_node	*target_node;
 */

//operations_combinations.c
void			ps_pa_then_ra(t_stack_node **stack_a, t_stack_node **stack_b);
void			ps_ra_then_pa_then_rra(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			rotate_stack_a_radix(t_stack_node **stack_a);
void			reverse_rotate_stack_a_radix(t_stack_node **stack_a);

//operations_push.c
void			pa(t_stack_node	**stack_a, t_stack_node **stack_b);
void			pb(t_stack_node	**stack_b, t_stack_node **stack_a);

//operations_reverse_rotate.c
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);

//operations_rotate.c
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);

//operations_swap.c
void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);

//parse_arguments.c
int				ps_atoi(const char *str);
t_stack_node	*ps_parse_args_in_quotes(char *argv[]);
void			ps_parse_and_insert_arguments(t_stack_node **stack_a,
					char *argv[], int *num_elements);
// t_stack_node	*ps_read_values_and_push_onto_stack_a(int argc, char *argv[]);

//ps_check_utils.c
int				ps_checkdup(t_stack_node *stack_a);
void			ps_check_stack_and_display_error(t_stack_node *stack_a);
int				ps_check_if_sorted(t_stack_node *stack_a);

//ps_find_index_utils.c
int				ps_find_index(t_stack_node *stack, int number);
int				ps_find_correct_place_in_stack_b(t_stack_node *stack_b,
					int nbr_to_insert);
int				ps_find_correct_place_in_stack_a(t_stack_node *stack_a,
					int nbr_to_insert);

//ps_find_utils.c
t_stack_node	*ps_find_last_element(t_stack_node	*stack);
int				ps_stack_size(t_stack_node	*stack);
int				ps_find_min_value(t_stack_node *stack);
t_stack_node	*ps_min_node(t_stack_node *stack);
t_stack_node	*ps_max_node(t_stack_node *stack);

//ps_list_utils.c
void			ps_stack_rank(t_stack_node *stack);
t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value);
void			copy_stack(t_stack_node **source, t_stack_node **destination);

//ps_memory_utils.c
void			ps_free_stack(t_stack_node **stack);
void			ps_free_str(char **input_array_of_str);
void			*ps_safe_malloc(size_t size);

//ps_print_utils.c
void			ps_print_stack(t_stack_node *stack);
void			ps_print_stack_start_finish(t_stack_node *stack);
void			ps_error_message(void);

//ps_split.c
char			**ft_split(char const *s, char c);

//sort_2_and_3_numbers.c 
void			ps_sort_2_numbers(t_stack_node **stack_a);
void			ps_sort_3_numbers(t_stack_node **stack_a);

//sort_5_numbers.c
void			first_stack(t_stack_node **stack_a, t_stack_node **stack_b);
void			second_stack(t_stack_node **stack_a, t_stack_node **stack_b);
void			ps_sort_5_numbers(t_stack_node **stack_a,
					t_stack_node **stack_b);

//sort_more_than_5_numbers.c
void			sort_section_of_list(t_stack_node **head);
void			swap_stack_a_first_time(t_stack_node **stack_a,
					t_stack_node **copy_swap_stack_a);
void			swap_stack_a_second_time(t_stack_node **stack_a,
					t_stack_node **copy_swap_stack_a);
void			swap_stack_a_third_time(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			ps_sort_beyond_5_numbers(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b);	
t_stack_node	*merge(t_stack_node *left, t_stack_node *right,
					t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*merge_sort(t_stack_node *stack_a, t_stack_node **stack_b, int size);
bool 			is_sorted_ascending(t_stack_node *stack_a);
bool			is_sorted_descending(t_stack_node* stack);
bool			is_in_top_half(int element_position, int stack_size);
t_stack_node	*find_element_with_rank(t_stack_node** stack, int target_rank);
int				get_target_position(t_stack_node* stack, int target_rank);
void			ps_update_positions(t_stack_node* stack);

#endif