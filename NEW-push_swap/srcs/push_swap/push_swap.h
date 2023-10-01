/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:53 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 18:06:38 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../../libs/printf/ft_printf.h"


typedef struct stack_node
{
	long				value;
	long				index;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_stack_node;

//calculate_ab.c
int				ps_case_rarb(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rrarrb(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rrarb(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rarrb(t_stack_node *a, t_stack_node *b, int required_value);

//calculate_ba.c
int				ps_case_rarb_a(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rrarrb_a(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rarrb_a(t_stack_node *a, t_stack_node *b, int required_value);
int				ps_case_rrarb_a(t_stack_node *a, t_stack_node *b, int required_value);

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
t_stack_node	*ps_parse_args_in_quotes(char **argv[]);
t_stack_node	*ps_read_values_and_push_onto_stack_a(int argc, char *argv[]);

//ps_check_utils.c
int				ps_checkdup(t_stack_node *stack_a);
int				ps_check_if_sorted(t_stack_node *stack_a);

//ps_find_index_utils.c
int				ps_find_index(t_stack_node *stack, int number);
int				ps_find_correct_place_in_stack_b(t_stack_node *stack_b,
					int nbr_to_insert);
int				ps_find_correct_place_in_stack_a(t_stack_node *stack_a,
					int nbr_to_insert);

//ps_find_utils.c
t_stack_node	*ps_find_last_element(t_stack_node	*stack);
int				ps_find_stack_size(t_stack_node	*stack);
int				ps_find_min_value(t_stack_node *stack);
int				ps_find_max_value(t_stack_node *stack);

//ps_list_utils.c
t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value);

//ps_memory_utils.c
void			ps_free_stack(t_stack_node **stack);
void			ps_free_str(char **input_array_of_str);
void			*ps_safe_malloc(size_t size);

//ps_print_utils.c
void			ps_print_stack(t_stack_node *stack);
void			ps_error_message(void);

//rotate_and_push_type.c
int				ps_use_rarb(t_stack_node **stack_a, t_stack_node **stack_b,
					int required_value, int stack_choice);
int				ps_use_rrarrb(t_stack_node **stack_a, t_stack_node **stack_b,
					int required_value, int stack_choice);
int				ps_use_rrarb(t_stack_node **stack_a, t_stack_node **stack_b,
					int required_value, int stack_choice);
int				ps_use_rarrb(t_stack_node **stack_a, t_stack_node **stack_b,
					int required_value, int stack_choice);					

//rotate_type.c
int				ps_rotate_type_ba(t_stack_node *a, t_stack_node *b);
int				ps_rotate_type_ab(t_stack_node *a, t_stack_node *b);

//sort_few.c 
void			ps_sort_two_elements(t_stack_node **stack_a);
void			ps_sort_three_elements(t_stack_node **stack_a);

//sort_many.c
void			ps_sort_b_until_3(t_stack_node **stack_a, t_stack_node **stack_b);
int				ps_sort_onto_stack_b(t_stack_node **stack_a);
t_stack_node	**ps_sort_back_onto_stack_a(t_stack_node **stack_a);
void			ps_sort(t_stack_node **stack_a);

//split.c
char			**ft_split(char const *s, char c);

#endif