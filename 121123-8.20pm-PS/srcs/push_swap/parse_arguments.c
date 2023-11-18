/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:09:26 by atang             #+#    #+#             */
/*   Updated: 2023/11/18 17:45:53 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static char **ft_split_inside_quotes(char const *s, char c) {
    char **result = NULL;
    int word_count = 0;

    // Count the number of words inside double quotes
    while (*s) {
        if (*s == '"') {
            s++;
            while (*s != '"' && *s) {
                if (*s == c) {
                    word_count++;
                    while (*s == c && *s) {
                        s++;
                    }
                } else {
                    s++;
                }
            }
            if (*s == '"') {
                word_count++;
                s++;
            }
        } else {
            s++;
        }
    }

    // Allocate memory for words
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;

    int i = 0;

    // Extract words inside double quotes
    while (*s) {
        if (*s == '"') {
            s++;
            int word_len = 0;
            const char *start = s;

            while (*s != '"' && *s) {
                if (*s == c) {
                    result[i] = (char *)malloc((word_len + 1) * sizeof(char));
                    if (result[i] == NULL) {
                        // Handle memory allocation failure
                        return NULL;
                    }
                    int j = 0;
                    while (start != s) {
                        result[i][j++] = *start++;
                    }
                    result[i++][j] = '\0';

                    while (*s == c && *s) {
                        s++;
                    }
                    start = s;
                    word_len = 0;
                } else {
                    s++;
                    word_len++;
                }
            }
            if (*s == '"') {
                result[i] = (char *)malloc((word_len + 1) * sizeof(char));
                if (result[i] == NULL) {
                    // Handle memory allocation failure
                    return NULL;
                }
                int j = 0;
                while (start != s) {
                    result[i][j++] = *start++;
                }
                result[i++][j] = '\0';
                s++;
            }
        } else {
            s++;
        }
    }

    result[i] = NULL;
    return result;
}
*/

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

/*
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
*/

// Handles INT MAX but makes it worse
int ps_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int signEncountered = 0; // Add a flag to track whether a sign character was encountered

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
        || *str == '\v' || *str == '\f' || *str == '\"')
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
            ft_printf("ATOI error\n");
        }

        result = (result * 10) + digit;
        str++;
    }

    // Check if a sign character was encountered but no digits followed it
    if (signEncountered && result == 0)
    {
        ps_error_message(); // Handle error with a message
        ft_printf("Sign but no digits\n");
    }

    // Multiply the result by the sign to account for positive or negative values
    return result * sign;
}

int ps_parse_args_in_quotes(char **quoted_arg, t_stack_node **stack_a, int *num_elements)
{
    printf("Converted arguments in quotes");
   
    while (*quoted_arg)
    {
        // Remove opening quote
        if ((*quoted_arg)[0] == '"')
        {
            (*quoted_arg)++;
        }
        // Remove closing quote
        int len = ps_strlen(*quoted_arg);
        if ((*quoted_arg)[len - 1] == '"')
        {
            (*quoted_arg)[len - 1] = '\0';
        }
        char *current_arg = *quoted_arg;
        char **split_args = ft_split(current_arg, ' ');
        if (split_args == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        int i = 0;
        int value;
        while (split_args[i])
        {
            if (!is_valid_integer(split_args[i]))
            {
                printf("Invalid argument: %s\n", split_args[i]);
                int j = 0;
                while (split_args[j])
                {
                    free(split_args[j]);
                    j++;
                }
                free(split_args); // Free the allocated memory
                return 1;
            }
            value = ps_atoi(split_args[i]);
            *stack_a = ps_create_and_insert_node(*stack_a, value);
            (*num_elements)++;
            i++;
        }
        int k = 0;
        while (split_args[k])
        {
            free(split_args[k]);
            k++;
        }
        free(split_args); // Free the allocated memory
        quoted_arg++;
    }
    printf("Converted arguments in quotes");
    return (0);
}

int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements)
{
    int value;

    while (*argv)
    {
        if (!is_valid_integer(*argv))
        {
            ps_error_message();
            ft_printf("Not integer\n");
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
// NEWEST WORKING
int ps_parse_and_insert_arguments(t_stack_node **stack_a, char *argv[], int *num_elements)
{
    int value;

     while (*argv)
     {
        if (**argv == '\"')
        {
            (*argv)++; // Move past the opening quote
            char *quoted_arg = *argv;

            while (*argv && **argv != '\"') {
                (*argv)++;
            }

            if (!*argv) {
                ft_printf("Unclosed double quote in quoted argument\n");
                return 1;
            }
            **argv = '\0'; // Terminate the quoted argument at the closing quote

            while (*quoted_arg) {
                // Skip leading spaces
                while (*quoted_arg == ' ')
                    quoted_arg++;

                // Find the end of the current token
                char *end = quoted_arg;
                while (*end && *end != ' ')
                    end++;

                // Check if the current token is a valid integer
                if (!is_valid_integer(quoted_arg)) {
                    ft_printf("Invalid argument: %.*s\n", (int)(end - quoted_arg), quoted_arg);
                    return 1;
                }

                // Convert and add the valid integer to the linked list
                value = atoi(quoted_arg);
                *stack_a = ps_create_and_insert_node(*stack_a, value);
                (*num_elements)++;

                // Move to the next token
                quoted_arg = end;
            }
        }
        else
        {
            if (!is_valid_integer(*argv))
            {
                ps_error_message();
                ft_printf("Not integer\n");
                return 1;
            }
            value = ps_atoi(*argv);
            *stack_a = ps_create_and_insert_node(*stack_a, value);
            (*num_elements)++;
        }
        argv++;
    }
    return (0);
}
*/

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
                *stack_a = ps_parse_args_in_quotes(&(*argv));
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
