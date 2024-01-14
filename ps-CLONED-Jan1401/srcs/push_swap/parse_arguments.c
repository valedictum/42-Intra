/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:09:26 by atang             #+#    #+#             */
/*   Updated: 2023/11/19 18:10:34 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


bool is_valid_integer(const char *str)
{
    if (*str == '-' || *str == '+') // Skip optional sign
        str++;

    while (*str) {
        if (!ps_is_digit(*str)) // Check if each character is a digit
            return false;
        str++;
    }

    return true;
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
int ps_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int signEncountered = 0;

    ft_printf("ps_atoi: Parsing \"%s\"\n", str);

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f') {
        str++;
    }

    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        signEncountered = 1;
        str++;
    }

    while (ps_is_digit(*str)) {
        int digit = *str - '0';

        // Check for potential overflow before accumulating the result
        if (result > (INT_MAX - digit) / 10) {
            ft_printf("Error: Overflow during atoi conversion.\n");
            return 0;  // Return an error code
        }

        result = (result * 10) + digit;
        str++;
    }

    // Check if a sign character was encountered but no digits followed it
    if (signEncountered && result == 0) {
        ft_printf("Error: Sign character without following digits.\n");
        return 0;  // Return an error code
    }

    // Multiply the result by the sign to account for positive or negative values
    return result * sign;
}

int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements) {
    while (*argv) {
        if (**argv == '\"') {
            (*argv)++; // Skip the double quote character
            char *quoted_arg = *argv;

            while (*quoted_arg && *quoted_arg != '\"') {
                if (!ps_is_digit(*quoted_arg) && *quoted_arg != '-' && *quoted_arg != '+') {
                    ft_printf("Error: Invalid character in quoted argument: %c\n", *quoted_arg);
                    return 1; // Return an error code
                }
                quoted_arg++;
            }

            if (*quoted_arg == '\"') {
                *stack_a = ps_parse_args_in_quotes(argv);
                (*num_elements)++;
            } else {
                ft_printf("Error: Unclosed double quote in quoted argument.\n");
                return 1; // Return an error code
            }
        } else {
            int is_valid = 1;
            char *arg = *argv;

            while (*arg) {
                if (*arg != ' ' && !ps_is_digit(*arg) && *arg != '-' && *arg != '+') {
                    ft_printf("Error: Invalid character in argument: %c\n", *arg);
                    return 1; // Return an error code
                }
                arg++;
            }

            if (is_valid && *arg != ' ') {
                int value = ps_atoi(*argv);
                *stack_a = ps_create_and_insert_node(*stack_a, value);
                (*num_elements)++;
            }
        }
        argv++;
    }
    return 0; // Return 0 for success
}
*/

t_stack_node *ps_parse_args_in_quotes(char *argv[]) {
    t_stack_node *stack_a = NULL;
    char **temp = ft_split(&argv[1][1], ' '); // Skip the opening double quote

    if (!temp) {
        //ft_printf("Error: Memory allocation failed for temp.\n");
        return stack_a;
    }

    int i = 0;
    while (temp[i]) {
        int value = ps_atoi(temp[i]);
        stack_a = ps_create_and_insert_node(stack_a, value);
        i++;
    }

    // Free the memory allocated for temp
    ps_free_str(temp);

    // Optionally print a message after successful parsing
    //ft_printf("Parsed in quotes\n");

    return stack_a;
}

int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements)
{
    int value;

    while (*argv)
    {
        if (!is_valid_integer(*argv))
        {
            ps_error_message();
            //ft_printf("Not integer\n");
            return 1;
        }
        value = ps_atoi(*argv);
        *stack_a = ps_create_and_insert_node(*stack_a, value);
        (*num_elements)++;
        argv++;
    }
    return 0;
}


/*
// WORKING!!!
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
        } else {
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
    }
    return 0;
}
*/
