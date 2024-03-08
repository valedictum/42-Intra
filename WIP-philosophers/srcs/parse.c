/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:12:22 by sentry            #+#    #+#             */
/*   Updated: 2024/03/04 07:54:38 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
	{
		str++;
	}
	return (str);
}

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

void    parse_input(t_data *data, char **argv)
{
    data->num_of_philos = philo_atol(argv[1]);
    data->time_to_die = philo_atol(argv[2]);
    data->time_to_eat = philo_atol(argv[3]);
    data->time_to_sleep = philo_atol(argv[4]);
    if (argv[5])
        data->num_of_eats = philo_atol(argv[5]);
}
