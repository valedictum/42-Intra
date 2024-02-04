/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:44:35 by atang             #+#    #+#             */
/*   Updated: 2024/02/04 19:41:05 by atang            ###   ########.fr       */
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
}

void	ps_print_stack_start_finish(t_stack_node *stack)
{
	int	position;

	position = 1;
	while (stack != NULL)
	{
		ft_printf(" %d (Position:%d, Rank:%d)\n", stack->value,
			stack->position, stack->rank);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ps_error_message_and_exit(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	ps_error_message(void)
{
	write (2, "Error\n", 6);
	return (1);
}

void	print_stack_state(const char	*label, t_stack_node *stack)
{
	ft_printf("%s:\n", label);
	if (stack == NULL)
	{
		ft_printf("--Empty--\n");
	}
	else
	{
		ps_print_stack(stack);
	}
	ft_printf("\n");
}
