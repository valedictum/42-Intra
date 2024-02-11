/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2024/02/11 11:28:53 by sentry           ###   ########.fr       */
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

// check.c
int     is_digit(int c);
bool	valid_integer(const char *str);
int     check_dupe(t_stack_node *stack_a);
void	check_stack_and_display_error(t_stack_node *stack_a);

// error.c
int     error_message(void);

// memory.c
void    free_split_arguments(char **split_arguments);
void	*safe_malloc(size_t size);
void	free_stack(t_stack_node **stack);

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
int             ps_atoi(const char *str);
t_stack_node	*create_and_insert_node(t_stack_node *stack, int value);
int             parse_and_insert(t_stack_node **stack_a, char *argv[], int *num_elements);

// print.c
void	print_stack(t_stack_node *stack);

// push_swap.c
void	choose_sort(t_stack_node **stack_a, t_stack_node **stack_b,
		int *operation_count, int num_elements);

// sort_small.c
void	sort_2(t_stack_node **stack_a, int *operation_count);
void	sort_3(t_stack_node **stack_a, int *operation_count);
void	sort_5(t_stack_node	**stack_a, t_stack_node	**stack_b,
		int	*operation_count);

// split.c
int     count_words(char const *s, char c);
char	*extract_word(char const **s, char c);
void	free_words(char **words);
char	**ft_split(char const *s, char c);

// stack.c
void			stack_rank(t_stack_node *stack);
t_stack_node	*find_rank(t_stack_node **stack, int target_rank);
int				stack_size(t_stack_node	*stack);

#endif