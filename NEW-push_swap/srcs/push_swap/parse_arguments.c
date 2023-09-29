/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:09:26 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 12:38:45 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

t_stack_node	*ps_parse_args_in_quotes(char **argv[])
{
	t_stack_node	*stack_a;
	char			**temp;
	int				i;
	int				value;

	stack_a = NULL;
	i = 0;
	if (!argv[1])
	{
		ft_printf("Error: No argument provided in quotes.\n");
		return (stack_a);
	}
	temp = ft_split(argv[1], ' ');
	if (!temp)
	{
		ft_printf("Error: Memory allocation failed for temp.\n")
		return (stack_a);
	}
	while (temp[i])
	{
		value = ps_atoi(argv[i]);
		stack_a = ps_create_and_insert_node(stack_a, value);
		i++;
	}
	ps_free_str(temp);
	free(temp);
	return (stack_a);
}

t_stack_node	*ps_read_values_and_push_onto_stack_a(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*new_node;
	int				i;
	int				value;

	stack_a = NULL;
	i = argc - 1;
	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments provided.\n");
		return (stack_a);
	}
	else if (argc == 2)
		stack_a = ps_parse_args_in_quotes(argv);
	else
	{
		while (i >= 2)
		{
			value = ps_atoi(argv[i]);
			stack_a = ps_create_and_insert_node(stack_a, value);
			i--;
		}
	}
	return (stack_a);
}