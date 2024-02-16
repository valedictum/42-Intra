/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:32:56 by sentry            #+#    #+#             */
/*   Updated: 2024/02/16 18:58:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str)
{
	int	result;
	int	sign;
	int	sign_encountered;
	int	digit;

	result = 0;
	sign = 1;
	sign_encountered = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		sign_encountered = 1;
		str++;
	}
	else if (*str == '+')
	{
		sign_encountered = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > (INT_MAX - digit) / 10)
		{
			error_message();
			exit(1);
		}
		result = (result * 10) + digit;
		str++;
	}
	if (sign_encountered && result == 0)
		error_message();
	return (result * sign);
}

t_stack_node	*create_and_insert_node(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;
	int				position;

	new_node = (t_stack_node *)safe_malloc(sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->position = 0;
	if (stack == NULL)
	{
		new_node->position = 1;
		return (new_node);
	}
	current = stack;
	position = 1;
	while (current->next != NULL)
	{
		position++;
		current = current->next;
	}
	new_node->position = position + 1;
	current->next = new_node;
	return (stack);
}

int	parse_and_insert(t_stack_node **stack_a, char *argv[], int *num_elements)
{
	int	value;

	while (*argv)
	{
		if (!valid_integer(*argv))
		{
			error_message();
			exit (1);
		}
		value = ps_atoi(*argv);
		*stack_a = create_and_insert_node(*stack_a, value);
		(*num_elements)++;
		argv++;
	}
	if (*num_elements == 1)
	{
		exit(0);
	}
	return (0);
}
