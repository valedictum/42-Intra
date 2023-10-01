/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:40:57 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 17:54:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_case_rarb_a(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = ps_find_correct_place_in_stack_a(a, required_value);
	if (i < ps_find_index(b, required_value))
		i = ps_find_index(b, required_value);
	return (i);
}

int	ps_case_rrarrb_a(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_correct_place_in_stack_a(a, required_value))
		i = ps_find_stack_size(a) - ps_find_correct_place_in_stack_a(a, required_value);
	if ((i < (ps_find_stack_size(b) - ps_find_index(b, required_value)))
		&& ps_find_index(b, required_value))
		i = ps_find_stack_size(b) - ps_find_index(b, required_value);
	return (i);
}

int	ps_case_rarrb_a(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_index(b, required_value))
		i = ps_find_stack_size(b) - ps_find_index(b, required_value);
	i = ps_find_correct_place_in_stack_a(a, required_value) + i;
	return (i);
}

int	ps_case_rrarb_a(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_correct_place_in_stack_a(a, required_value))
		i = ps_find_stack_size(a) - ps_find_correct_place_in_stack_a(a, required_value);
	i = ps_find_index(b, required_value) + i;
	return (i);
}