/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:30 by atang             #+#    #+#             */
/*   Updated: 2024/04/28 11:11:54 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Example of correct input - ./philo 5 800 200 200 [5]

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
		init_table(&table);
		start_dinner(&table);
		clean(&table);
	}
	else
	{
		error_exit("Incorrect input!\nCorrect format is: ./philo " \
			"[number_of_philosophers] [time_to_die] [time_to_eat] " \
			"[time_to_sleep] " \
			"(optional)[number_of_times_each_philosopher_must_eat]");
	}
}
