/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_run_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:27:17 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:27:18 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libpush_swap.h"

void	run_operation_checker(t_stack *stack_a, t_stack *stack_b, int op)
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
}

int	convert_command(char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		return (SA);
	if (ft_strncmp(str, "sb", 3) == 0)
		return (SB);
	if (ft_strncmp(str, "ss", 3) == 0)
		return (SS);
	if (ft_strncmp(str, "pa", 3) == 0)
		return (PA);
	if (ft_strncmp(str, "pb", 3) == 0)
		return (PB);
	if (ft_strncmp(str, "ra", 3) == 0)
		return (RA);
	if (ft_strncmp(str, "rb", 3) == 0)
		return (RB);
	if (ft_strncmp(str, "rr", 3) == 0)
		return (RR);
	if (ft_strncmp(str, "rra", 3) == 0)
		return (RRA);
	if (ft_strncmp(str, "rrb", 3) == 0)
		return (RRB);
	if (ft_strncmp(str, "rrr", 3) == 0)
		return (RRR);
	return (-1);
}

void	run_commands(t_command *list, t_stack *stack_a, t_stack *stack_b)
{
	t_command	*current;

	current = list;
	while (current)
	{
		run_operation_checker(stack_a, stack_b, current->command);
		current = current->next;
	}
}

void	free_list(t_command *list)
{
	t_command	*current;
	t_command	*temp;

	current = list;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
