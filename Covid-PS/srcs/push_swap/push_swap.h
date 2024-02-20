/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2024/02/20 15:48:18 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h> 
# include "../../libs/printf/ft_printf.h"

typedef struct s_stack_node
{
	long				value;
	int					rank;
	int					position;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_chunk_node
{
	t_stack_node		*element;
	struct s_chunk_node	*next;
}	t_chunk_node;

typedef struct s_chunk_info
{
	t_chunk_node		*head;
	t_chunk_node		*tail;
	int					start_rank;
	int					end_rank;
}	t_chunk_info;

// check.c
int				is_digit(int c);
bool			valid_integer(const char *str);
int				check_dupe(t_stack_node *stack_a);
void			check_stack_and_display_error(t_stack_node *stack_a);
bool			is_sorted(t_stack_node *stack);

// chunk.c
t_chunk_node	*create_chunk_node(t_stack_node *element);
void			set_chunk_null(t_chunk_node **chunk_head,
					t_chunk_node **chunk_tail);
void			add_to_chunk(t_chunk_node **chunk_head,
					t_chunk_node **chunk_tail, t_stack_node *element);
void			push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
					t_chunk_node **chunk_head, int *operation_count);

// chunk_utils.c
int				max_rank(t_stack_node *stack);
void			update_positions(t_stack_node *stack);
void			rotate_to_top_of_a(t_stack_node **stack, t_stack_node *target,
					int	*operation_count);
void			rotate_to_top_of_b(t_stack_node **stack, t_stack_node *target,
					int	*operation_count);

// error.c
int				error_message(void);

// memory.c
void			free_split_arguments(char **split_arguments);
void			*safe_malloc(size_t size);
void			free_stack(t_stack_node **stack);

// operations_push.c
void			pa(t_stack_node	**stack_a, t_stack_node **stack_b,
					int *operation_count);
void			pb(t_stack_node	**stack_b, t_stack_node **stack_a,
					int *operation_count);

// operations_reverse_rotate.c
void			rra(t_stack_node **stack_a, int *operation_count);
void			rrb(t_stack_node **stack_b, int *operation_count);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

// operations_rotate.c
void			ra(t_stack_node **stack_a, int *operation_count);
void			rb(t_stack_node **stack_b, int *operation_count);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

// operations_swap.c
void			sa(t_stack_node **stack_a, int *operation_count);
void			sb(t_stack_node **stack_b, int *operation_count);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);

// parse.c
int				ps_atoi(const char *str);
t_stack_node	*create_and_insert_node(t_stack_node *stack, int value);
int				parse_and_insert(t_stack_node **stack_a, char *argv[],
					int *num_elements);

// print.c
void			print_stack(t_stack_node *stack);

// push_swap.c
void			choose_sort(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count, int num_elements);

// sort_helpers.c
int				is_in_chunk_range(t_stack_node *current,
					t_stack_node **stack_a, int i, int total_chunks);
void			process_chunk_3(t_stack_node **stack_a, t_stack_node **stack_b,
					int	*operation_count, int i);
void			process_chunk_500(t_stack_node **stack_a,
					t_stack_node **stack_b, int	*operation_count, int i);

// sort_small.c
void			sort_2(t_stack_node **stack_a, int *operation_count);
void			sort_3(t_stack_node **stack_a, int *operation_count);
void			sort_5(t_stack_node	**stack_a, t_stack_node	**stack_b,
					int	*operation_count);

// sort_large.c
int				check_if_sorted_descending(t_stack_node *stack_a);
void			chunk_sort_3(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count, int max_rank);
void			chunk_sort_500(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count);
void			insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
					int	*operation_count);

// split.c
int				count_words(char const *s, char c);
char			*extract_word(char const **s, char c);
void			free_words(char **words);
char			**ft_split(char const *s, char c);

// stack.c
void			stack_rank(t_stack_node *stack);
t_stack_node	*find_rank(t_stack_node **stack, int target_rank);
int				stack_size(t_stack_node	*stack);

#endif