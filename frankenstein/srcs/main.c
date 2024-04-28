/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:30 by atang             #+#    #+#             */
/*   Updated: 2024/04/28 18:41:51 by atang            ###   ########.fr       */
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
		dinner_start(&table);
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
