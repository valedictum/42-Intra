/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:43 by tday              #+#    #+#             */
/*   Updated: 2023/12/19 21:26:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
checks if a character is a digit.

returns 1 (true) if it is a digit.
returns 0 (false) if it isn't.
essentially a bool.
*/
static inline int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

/*
checks if a character is a space.

returns 1 (true) if it is a space.
returns 0 (false) if it isn't.
essentially a bool.
*/
static inline int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	else
		return (false);
}

/*
Summary
the valid_input function checks if a given string represents a valid input.
it skips over whitespace characters and verifies that the string contains a
positive integer that is 10 digits or less. 

if it encounters a '-' or non-digit character it will throw an error.

Inputs
str: a pointer to the string to be checked.

Outputs
number: a pointer to the start of a valid number within the input string.
*/
static const char	*valid_input(const char *str)
{
	int			length;
	const char	*number;

	length = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("negative input invalid");
	if (!is_digit(*str))
		error_exit("input not a digit");
	number = str;
	while (is_digit(*str++))
		++ length;
	if (length > 10)
		error_exit("value must be within int range");
	return (number);
}

/*
Summary
converts a string representation of a number into a 'long' integer.
uses valid_input to verify that the string contains a positive integer that is
less than 10 digits or less.
converts the characters to a long integer.
checks that the integer is <= INT_MAX.

Inputs
str: a pointer to the string representation of the number to be converted.

Outputs
result: the converted 'long' integer value of the input string.
*/
static long	ft_atolong(const char *str)
{
	long	result;

	result = 0;
	str = valid_input(str);
	while (is_digit(*str))
		result = (result * 10) + (*str++ - '0');
	if (result > INT_MAX)
		error_exit("value must be within int range");
	return (result);
}

/*
Summary
converts the command line arguments into the appropriate data types for the
't_data' struct.

Inputs
data: a pointer to the 't_data' struct that will store the parsed values.
argv[]: an array of strings containing the command line arguments.

Outputs
none. the parsed values are stored in the 'data' struct. 
*/
void	parse_input(t_data *data, char *argv[])
{
	data->num_of_philos = ft_atolong(argv[1]);
	data->time_to_die = ft_atolong(argv[2]) * 1000;
	data->time_to_eat = ft_atolong(argv[3]) * 1000;
	data->time_to_sleep = ft_atolong(argv[4]) * 1000;
	if (data->time_to_die < 60000
		|| data->time_to_eat < 60000
		|| data->time_to_sleep < 60000)
		error_exit("timstamps need to be > 60ms");
	if (argv[5])
		data->meals_limit = ft_atolong(argv[5]);
	else
		data->meals_limit = -1;
}
