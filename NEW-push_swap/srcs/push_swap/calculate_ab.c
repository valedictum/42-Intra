/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:40:47 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 17:53:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_case_rarb(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = ps_find_correct_place_in_stack_b(b, required_value);
	if (i < ps_find_index(a, required_value))
		i = ps_find_index(a, required_value);
	return (i);
}

int	ps_case_rrarrb(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_correct_place_in_stack_b(b, required_value))
		i = ps_find_stack_size(b)
			- ps_find_correct_place_in_stack_b(b, required_value);
	if ((i < (ps_find_stack_size(a) - ps_find_index(a, required_value)))
		&& ps_find_index(a, required_value))
		i = ps_find_stack_size(a) - ps_find_index(a, required_value);
	return (i);
}

int	ps_case_rrarb(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_index(a, required_value))
		i = ps_find_stack_size(a) - ps_find_index(a, required_value);
	i = ps_find_correct_place_in_stack_b(b, required_value) + i;
	return (i);
}

int	ps_case_rarrb(t_stack_node *a, t_stack_node *b, int required_value)
{
	int	i;

	i = 0;
	if (ps_find_correct_place_in_stack_b(b, required_value))
		i = ps_find_stack_size(b)
			- ps_find_correct_place_in_stack_b(b, required_value);
	i = ps_find_index(a, required_value) + i;
	return (i);
}
