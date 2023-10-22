/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:41:31 by atang             #+#    #+#             */
/*   Updated: 2023/10/22 16:57:32 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_dupe(t_stack_node *stack_a)
{
	t_stack_node	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->value == temp->value)
				return (1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ps_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int is_valid_integer(long value){
    // Check if the value is within the valid integer range
    if (value >= INT_MIN && value <= INT_MAX) {
        return 1;
    }
    return 0;
}
 */

/*
int ps_check_syntax(long value) 
{
    char sign;

    if (value < 0)
        sign = '-';
    else if (value >= 0)
        sign = '+';
    else
        return (1);

    if (sign != '+' && sign != '-')
        return (1);

    return (0);
}
*/


/*
int is_valid_integer(const char *str) {
    if (*str == '+' || *str == '-') {
        str++; // Skip the sign character
    }

    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0; // Non-digit character found, not a valid integer
        }
        str++;
    }
    return 1;
}
*/

/*
int ps_check_syntax(int value) {
    int value = ps_atoi(str);
    if (value == 0 && str[0] != '0') {
        return 1; // Invalid input, not a valid integer
    }
    if (value >= -2147483648 && value <= 2147483647) {
        return 0; // Valid 32-bit integer
    }
    return 1; // Out of range integer
}
*/


/*
void	ps_check_stack_and_display_error(t_stack_node *stack_a)
{
	if (!stack_a || ps_check_dupe(stack_a))
	{
		ps_free_stack(&stack_a);
		ps_error_message();
		return;
	}
	while (stack_a)
	{
		if (!ps_check_syntax(stack_a->value))
		{
			ps_free_stack(&stack_a);
			ps_error_message();
			return;
		}
		stack_a = stack_a->next;
	}
}
*/

void	ps_check_stack_and_display_error(t_stack_node *stack_a)
{
	if (!stack_a || ps_check_dupe(stack_a))
	{
		ps_free_stack(&stack_a);
		ps_error_message();
	}
}

int	ps_check_if_sorted(t_stack_node *stack_a)
{
	int	prev_value;

	prev_value = INT_MIN;
	while (stack_a)
	{
		if (prev_value > stack_a->value)
			return (0);
		prev_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}

