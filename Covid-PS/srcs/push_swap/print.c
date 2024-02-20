/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:31:29 by sentry            #+#    #+#             */
/*   Updated: 2024/02/11 14:11:50 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf(" %d\n", stack->value);
		stack = stack->next;
	}
}
