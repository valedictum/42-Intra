/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:44:35 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 12:39:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%ld ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ps_error_message(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
