/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combinations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:15 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 16:39:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa_then_ra(t_stack_node **stack_a, t_stack_node **stack_b)
{
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	ps_ra_then_pa_then_rra(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	pa(stack_a, stack_b);
	rra(stack_a);
}

void	rotate_stack_a_radix(t_stack_node **stack_a)
{
	ra(stack_a);
	ra(stack_a);
}

void	reverse_rotate_stack_a_radix(t_stack_node **stack_a)
{
	rra(stack_a);
	rra(stack_a);
}
