/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2024/02/04 19:41:13 by atang            ###   ########.fr       */
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

typedef struct chunk_node
{
	t_stack_node		*element;
	struct chunk_node	*next;
}	t_chunk_node;

typedef struct chunk_info
{
	t_chunk_node		*head;
	t_chunk_node		*tail;
	int					start_rank;
	int					end_rank;
}	t_chunk_info;

//chunk_utils.c
t_chunk_node	*create_chunk_node(t_stack_node *element);
void			set_chunk_null(t_chunk_node **chunk_head,
					t_chunk_node **chunk_tail);
void			add_to_chunk(t_chunk_node **chunk_head,
					t_chunk_node **chunk_tail, t_stack_node *element);
void			push_chunk_to_b(t_stack_node **stack_a,
					t_stack_node **stack_b, t_chunk_node **chunk_head,
					int *operation_count);

//operations_push.c
void			pa(t_stack_node	**stack_a, t_stack_node **stack_b,
					int *operation_count);
void			pb(t_stack_node	**stack_b, t_stack_node **stack_a,
					int *operation_count);

//operations_reverse_rotate.c
void			rra(t_stack_node **stack_a, int *operation_count);
void			rrb(t_stack_node **stack_b, int *operation_count);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

//operations_rotate.c
void			ra(t_stack_node **stack_a, int *operation_count);
void			rb(t_stack_node **stack_b, int *operation_count);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

//operations_swap.c
void			sa(t_stack_node **stack_a, int *operation_count);
void			sb(t_stack_node **stack_b, int *operation_count);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

//parse_arguments.c
int				ps_atoi(const char *str);
t_stack_node	*ps_parse_args_in_quotes(char *argv[]);
int				ps_parse_and_insert_arguments(t_stack_node **stack_a,
					char *argv[], int *num_elements);
// t_stack_node	*ps_read_values_and_push_onto_stack_a(int argc, char *argv[]);

//ps_check_utils.c
int				ps_checkdup(t_stack_node *stack_a);
int				ps_is_digit(int c);
void			ps_check_stack_and_display_error(t_stack_node *stack_a);
int				ps_check_if_sorted(t_stack_node *stack_a);
bool			is_sorted(t_stack_node *stack);
int				ps_check_if_sorted_descending(t_stack_node *stack_a);

//ps_find_utils.c
size_t			ps_strlen(char *s);
t_stack_node	*ps_find_last_element(t_stack_node	*stack);
int				ps_stack_size(t_stack_node	*stack);
int				ps_find_min_value(t_stack_node *stack);
t_stack_node	*ps_min_node(t_stack_node *stack);
t_stack_node	*ps_max_node(t_stack_node *stack);
int				get_max_rank(t_stack_node *stack);
t_stack_node	*find_element_with_rank(t_stack_node **stack, int target_rank);

//ps_list_utils.c
void			ps_stack_rank(t_stack_node *stack);
t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value);
void			copy_stack(t_stack_node **source, t_stack_node **destination);
void			ps_update_positions(t_stack_node *stack);

//ps_memory_utils.c
void			ps_free_stack(t_stack_node **stack);
void			ps_free_str(char **input_array_of_str);
void			*safe_malloc(size_t size);

//ps_print_utils.c
void			ps_print_stack(t_stack_node *stack);
void			ps_print_stack_start_finish(t_stack_node *stack);
void			ps_error_message_and_exit(void);
int				ps_error_message(void);
void			print_stack_state(const char *label, t_stack_node *stack);

//ps_split.c
char			*extract_word(char const **s, char c);
void			free_words(char **words);
char			**ft_split(char const *s, char c);

//rotate to top.c
void			rotate_to_top_of_a(t_stack_node **stack, t_stack_node *target,
					int *operation_count);
void			rotate_to_top_of_b(t_stack_node **stack, t_stack_node *target,
					int *operation_count);

//sort_2_and_3_numbers.c 
void			ps_sort_2_numbers(t_stack_node **stack_a, int *operation_count);
void			ps_sort_3_numbers(t_stack_node **stack_a, int *operation_count);

//sort_5_numbers.c
void			ps_sort_5_numbers(t_stack_node **stack_a,
					t_stack_node **stack_b, int *operation_count);

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
void			chunk_sort_3(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			chunk_sort_2(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			chunk_sort_4(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			chunk_sort_100(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			chunk_sort_500(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
t_stack_node	*merge(t_stack_node *left, t_stack_node *right,
					t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*merge_sort(t_stack_node *stack_a, t_stack_node **stack_b,
					int size);
bool			is_sorted_ascending(t_stack_node *stack_a);
bool			is_sorted_descending(t_stack_node *stack);
bool			is_in_top_half(int element_position, int stack_size);
int				get_target_position(t_stack_node *stack, int target_rank);
void			push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
					t_chunk_node **chunk_head, int *operation_count);

#endif