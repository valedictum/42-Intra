/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:44:35 by atang             #+#    #+#             */
/*   Updated: 2023/10/15 19:36:10 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack_node *stack)
{
	int	position;

	position = 1;
	while (stack != NULL)
	{
		ft_printf(" %d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ps_print_stack_start_finish(t_stack_node *stack)
{
	int	position;

	position = 1;
	while (stack != NULL)
	{
		ft_printf(" %d (Position:%d, Rank:%d)\n", stack->value, stack->position, stack->rank);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ps_error_message(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

