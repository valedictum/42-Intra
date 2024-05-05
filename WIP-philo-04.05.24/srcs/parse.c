/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:12:22 by sentry            #+#    #+#             */
/*   Updated: 2024/05/04 20:46:04 by sentry           ###   ########.fr       */
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

/*
	Bool to check is digit
*/

static	inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
	Bool to check is space
*/

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/*
	1) 	Check for negatives
	2) 	Check if legit number "       +77%^" YES vs "    +#$42" NO
	3)	Check for INT_MAX 37648263864349659349579348797395767389467
		(check len > 10, sure > INT_MAX)
	Returns ptr to the actual number for atol
*/
static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Positive values only!");
	if (!is_digit(*str))
		error_exit("The input is not a valid digit!");
	number = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_exit("The value is too large, INT_MAX is the limit");
	return (number);
}

/*
	Convert the input to a long, created a valid_input fn() to check input
	validity - this INT_MAX check is for 2_147_483_648 <-> 9_999_999_999  
*/

static long	ft_atol(const char *str)
{
	long 	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		error_exit("Value is too large, INT_MAX is the limit");
	return (num);
}

/*
					ms		ms		ms
	./philo 	5	800 	200 	200 	[5]
	1) Actual numbers
	2) Not > INT_MAX
	3) Timestamps > 60ms

	Time is in millisecond BUT usleep fn() wants microseconds 
	(convert by x 1000 (1e3 is 1 with 3 zeros in scientific notation
	i.e. 1000))

	~1e3 = 1_000
 	~1e6 = 1_000_000

	INPUT 
 	[0] ./philo
	[1] number_of_philosophers
	[2] time_to_die
	[3] time_to_eat
	[4] time_to_sleep
	[5] [number_of_times_each_philosopher_must_eat]

	- Check for max 200 philos and timestamps > 60ms
	- nbr_limit_meals -1 acts as a flag: NO LIMITS
*/

void	parse_input(t_data *data, char **argv)
{
	data->philo_count = ft_atol(argv[1]);
	if (data->philo_count > PHILO_MAX)
	{
		printf(RED"Maximum number of philosophers cannnot exceed 200"RST);
		exit(EXIT_FAILURE);
	}
    data->time_to_die = ft_atol(argv[2]) * 1e3;
    data->time_to_eat = ft_atol(argv[3]) * 1e3;
    data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		error_exit("Use timestamps > 60ms for TTDIE, TTEAT, TTSLEEP");
    if (argv[5])
        data->meal_limit = ft_atol(argv[5]);
	else
		data->meal_limit = -1; 
}
