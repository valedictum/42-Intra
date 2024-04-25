/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:12:22 by sentry            #+#    #+#             */
/*   Updated: 2024/04/25 17:35:11 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
	MY: is_digit, valid_integer, skip_whitespace, handle_sign, philo_atol, and
	parse_input - 6 functions

- 1 -
static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

- 2 -
bool	valid_integer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}

- 3 -
const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
	{
		str++;
	}
	return (str);
}

- 4 -
static int	handle_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
        error_and_exit("Negative input invalid");
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

- 5 -
static long	philo_atol(const char *str)
{
	long	result;
    int		sign;
    int		digit;

	result = 0;
	str = skip_whitespace(str);
    sign = handle_sign(&str);
    if (!valid_integer(str))
    {
        error_and_exit("Non-integer input invalid");
    }
    while (is_digit(*str))
	{
		digit = *str - '0';
		if (result > (INT_MAX - digit) / 10)
		{
			error_and_exit("Overflow");
		}
		result = (result * 10) + digit;
		str++;
	}
	return (result * sign);
}

- 6 -
void    parse_input(t_data *data, char **argv)
{
    data->num_of_philos = philo_atol(argv[1]);
    data->time_to_die = philo_atol(argv[2]);
    data->time_to_eat = philo_atol(argv[3]);
    data->time_to_sleep = philo_atol(argv[4]);
    if (argv[5])
        data->num_limit_meals = philo_atol(argv[5]);
}
*/

static	inline bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/*
	1) 	Check for negatives
	2) 	Check if legit number "       +77%^" YES vs "    +#$42" NO
	3)	Check for INT_MAX 37648263864349659349579348797395767389467
		(check len > 10, sure > INT_MAX)
	returns ptr
*/
static const char	*valid_input(const char *str)
{
	int			len; //len of str
	const char	*number;

	len = 0;
	// 1) Skip the space
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_and_exit("Positive values only!");
	if (!is_digit(*str))
		error_and_exit("The input is not a correct digit!");
	number = str; // "             +77&%?"
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_and_exit("The value is too big, INT_MAX is the limit");
	return (number);
}

static long	ft_atol(const char *str)
{
	long 	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		error_and_exit("The value is too big, INT_MAX is the limit");
	return (num);
}

/*
					ms		ms		ms
	./philo 	5	800 	200 	200 	[5]
	1) Actual numbers
	2) Not > INT_MAX
	3) Timestamps > 60ms

	BUT USLEEP fn() wants microseconds (convert by x 1000 (1e3 is 1 with 3 zeros
	i.e. 1000))
*/

void    parse_input(t_data *data, char **argv)
{
    data->num_of_philos = ft_atol(argv[1]);
    data->time_to_die = ft_atol(argv[2]) * 1e3;
    data->time_to_eat = ft_atol(argv[3]) * 1e3;
    data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_eat < 6e4 || data->time_to_sleep < 6e4)
		error_and_exit("Use timestamps > 60ms");
    if (argv[5])
        data->num_limit_meals = ft_atol(argv[5]);
	else
		data->num_limit_meals = -1; 
}
