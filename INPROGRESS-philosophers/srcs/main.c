/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:30 by atang             #+#    #+#             */
/*   Updated: 2024/04/27 09:58:21 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 [5]

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		// correct_input
		// 1) Error checking, filling data
		parse_input(&data, argv);
		// 2) Creating the actual thing
		init_data(&data);
		// 3)
		start_dinner(&data);
		// 4) No leaks -> philos full | 1 philo died
		//clean(&data);

	}
	else
	{
		error_and_exit("Incorrect input!\nCorrect format is: ./philo " \
			"[number_of_philosophers] [time_to_die] [time_to_eat] " \
			"[time_to_sleep] (optional)[number_of_times_each_philosopher_must_eat]");
	}
}
