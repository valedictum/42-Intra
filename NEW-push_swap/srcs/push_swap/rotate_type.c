/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:17 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 12:43:14 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ps_rotate_type_ba(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*temp;

	temp = b;
	i = ps_case_rrarrb_a(a, b, b->value);
	while (temp)
	{
		if (i > ps_case_rarb_a(a, b, temp->value))
			i = ps_case_rarb_a(a, b, temp->value);
		if (i > ps_case_rrarrb_a(a, b, temp->value))
			i = ps_case_rrarrb_a(a, b, temp->value);
		if (i > ps_case_rarrb_a(a, b, temp->value))
			i = ps_case_rarrb_a(a, b, temp->value);
		if (i > ps_case_rrarb_a(a, b, temp->value))
			i = ps_case_rrarb_a(a, b, temp->value);
		temp = temp->next;
	}
	return (i);
}

int	ps_rotate_type_ab(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*temp;

	temp = a;
	i = ps_case_rrarrb(a, b, a->value);
	while (temp)
	{
		if (i > ps_case_rarb(a, b, temp->value))
			i = ps_case_rarb(a, b, temp->value);
		if (i > ps_case_rrarrb(a, b, temp->value))
			i = ps_case_rrarrb(a, b, temp->value);
		if (i > ps_case_rarrb(a, b, temp->value))
			i = ps_case_rarrb(a, b, temp->value);
		if (i > ps_case_rrarb(a, b, temp->value))
			i = ps_case_rrarb(a, b, temp->value);
		temp = temp->next;
	}
	return (i);
}
