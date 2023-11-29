/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:09:26 by atang             #+#    #+#             */
/*   Updated: 2023/11/18 08:41:20 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
// NO HANDLING OF INT MAX
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
*/

bool is_valid_integer(const char *str)
{
    if (*str == '-' || *str == '+') // Skip optional sign
        str++;

    while (*str) {
        if (!isdigit(*str)) // Check if each character is a digit
            return false;
        str++;
    }

    return true;
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

// Handles INT MAX but makes it worse
int ps_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int signEncountered = 0; // Add a flag to track whether a sign character was encountered

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
        || *str == '\v' || *str == '\f')
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        signEncountered = 1; // Set the sign flag
        str++;
    }
    else if (*str == '+')
    {
        signEncountered = 1; // Set the sign flag
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';

        // Check for potential overflow before accumulating the result
        if (result > (INT_MAX - digit) / 10)
        {
            ps_error_message(); // Handle error with a message
        }

        result = (result * 10) + digit;
        str++;
    }

    // Check if a sign character was encountered but no digits followed it
    if (signEncountered && result == 0)
    {
        ps_error_message(); // Handle error with a message
    }

    // Multiply the result by the sign to account for positive or negative values
    return result * sign;
}

/*
t_stack_node	*ps_parse_args_in_quotes(char *argv[])
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
		ft_printf("Error: Memory allocation failed for temp.\n");
		return (stack_a);
	}
	while (temp[i])
	{
		value = ps_atoi(temp[i]);
		stack_a = ps_create_and_insert_node(stack_a, value);
		i++;
	}
	ps_free_str(temp);
	return (stack_a);
}
*/

t_stack_node	*ps_parse_args_in_quotes(char *argv[])
{
	t_stack_node	*stack_a;
	int				value;
	int				i;
	char			**temp;

	stack_a = NULL;
	temp = ft_split(&argv[1][1], ' '); // Skip the opening double quote
	if (!temp)
	{
		ft_printf("Error: Memory allocation failed for temp.\n");
		return (stack_a);
	}

	i = 0;
	while (temp[i])
	{
		value = ps_atoi(temp[i]);
		stack_a = ps_create_and_insert_node(stack_a, value);
		i++;
	}

	// Free the memory allocated for temp
	ps_free_str(temp);

	// Optionally print a message after successful parsing
	ft_printf("Parsed in quotes\n");

	return (stack_a);
}

/*
t_stack_node	*ps_parse_args_in_quotes(char *argv[])
{
	t_stack_node	*stack_a;
	int				value;
	int				i;
	char			**temp;

	stack_a = NULL;
	temp = ft_split(argv[1], ' ');
	if (!temp)
	{
		ft_printf("Error: Memory allocation failed for temp.\n");
		return (stack_a);
	}
	i = 0;
	while (temp[i])
	{
		value = ps_atoi(temp[i]);
		stack_a = ps_create_and_insert_node(stack_a, value);
		i++;
	}
	ps_free_str(temp);
	return (stack_a);
}
*/

/*
// WORKING PARSE ARGUMENTS
int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements)
{
    int value;

    while (*argv)
    {
        if (**argv == '\"') {
            // Argument enclosed in double quotes
            (*argv)++; // Skip the double quote character
            *stack_a = ps_parse_args_in_quotes(argv);
            (*num_elements)++; // Increment the number of elements as needed
        } else {
            // Single argument (not enclosed in quotes)
            value = ps_atoi(*argv);
            *stack_a = ps_create_and_insert_node(*stack_a, value);
            (*num_elements)++;
        }
        argv++;
    }

    return 0;
}
*/
int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements)
{
    int value;

    while (*argv)
    {
        if (**argv == '\"') {
            // Argument enclosed in double quotes
            (*argv)++; // Skip the double quote character
            char *quoted_arg = *argv;

            while (*quoted_arg && *quoted_arg != '\"')
            {
                if (!ps_is_digit(*quoted_arg) && *quoted_arg != '-' && *quoted_arg != '+')
                {
                    ft_printf("Invalid character in quoted argument: %c\n", *quoted_arg);
                    return 1; // Raise an error
                }
                quoted_arg++;
            }

            if (*quoted_arg == '\"')
            {
                *stack_a = ps_parse_args_in_quotes(argv);
                (*num_elements)++; // Increment the number of elements as needed
            } else {
                ft_printf("Unclosed double quote in quoted argument\n");
                return 1; // Raise an error
            }
        } 
		/*
		EXISTING
		else {
            // Single argument (not enclosed in quotes)
            int is_valid = 1; // Flag to track if the argument is valid

            for (char *ch = *argv; *ch; ch++)
            {
                if (!ps_is_digit(*ch) && *ch != '-' && *ch != '+')
                {
                    return 1; // Raise an error
                }
            }

            if (is_valid)
            {
                value = ps_atoi(*argv);
                *stack_a = ps_create_and_insert_node(*stack_a, value);
                (*num_elements)++;
            }
        }
        argv++;
		*/
		else
		{
            // Single argument (not enclosed in quotes)
            if (!is_valid_integer(*argv))
			{
                ft_printf("Invalid argument: %s\n", *argv);
                return 1; // Raise an error
            }
            value = ps_atoi(*argv);
            *stack_a = ps_create_and_insert_node(*stack_a, value);
            (*num_elements)++;
        }
        argv++;
    }
    return 0;
}


/*
WORKING
int	ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[],
		int *num_elements)
{
	int	value;

	while (*argv)
	{
		value = ps_atoi(*argv);
		*stack_a = ps_create_and_insert_node(*stack_a, value);
		(*num_elements)++;
		argv++;
	}

	return (0);
}
*/

/* 
t_stack_node	*ps_read_values_and_push_onto_stack_a(int argc, char *argv[])
{
	t_stack_node	*stack_a;
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
 */