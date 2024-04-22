/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:00 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:30:02 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*get_operation(int op)
{
	if (op == SA || op == SB || op == SS)
		return (&swap);
	else if (op == PA || op == PB)
		return (&push);
	else if (op == RA || op == RB || op == RR)
		return (&rotate);
	else if (op == RRA || op == RRB || op == RRR)
		return (&reverse);
	else
		return (NULL);
}

bool	operation_check(int op)
{
	if (op == SA || op == SB || op == RA || op == RB || op == RRA || op == RRB
		|| op == SS || op == RR || op == RRR)
		return (true);
	return (false);
}

void	run_operation(t_stack *stack_a, t_stack *stack_b, int op)
{
	void	(*operate)(t_stack *);
	void	(*push_operate)(t_stack *, t_stack *);

	if (operation_check(op) == true)
		operate = (void (*)(t_stack *))get_operation(op);
	else
		push_operate = (void (*)(t_stack *, t_stack *))get_operation(op);
	if (op == SA || op == RA || op == RRA)
		operate(stack_a);
	else if (op == SB || op == RB || op == RRB)
		operate(stack_b);
	else if (op == SS || op == RR || op == RRR)
	{
		operate(stack_a);
		operate(stack_b);
	}
	if (op == PB)
		push_operate(stack_a, stack_b);
	else if (op == PA)
		push_operate(stack_b, stack_a);
	print_operation(op);
}

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
	{
		stack->number->position = BODY;
		stack->number = stack->number->next;
		stack->number->position = HEAD;
	}
	else
	{
		stack->number->prev->position = BODY;
		stack->number->next->position = HEAD;
		stack->number->position = BODY;
		stack->number = stack->number->next;
	}
}

void	reverse(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
	{
		stack->number->position = BODY;
		stack->number = stack->number->prev;
		stack->number->position = HEAD;
	}
	else
	{
		stack->number->prev->position = HEAD;
		stack->number->prev->prev->position = BODY;
		stack->number->position = BODY;
		stack->number = stack->number->prev;
	}
}
