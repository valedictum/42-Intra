/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:44:35 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 12:38:42 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
