/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:34:58 by tday              #+#    #+#             */
/*   Updated: 2023/12/23 18:21:50 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Summary
	the main function of this program.
	it checks that the correct number of command kine arguments have been used.
	parses the inputs from the command line arguments into the t_data struct.
	initialises the data, philos, & forks structs.
	starts the dinner simulation.
	destroys mutexes and frees memory after the simulation has finished.
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		parse_input(&data, argv);
		data_init(&data);
		dinner_start(&data);
		clean(&data);
	}
	else
	{
		error_exit("incorrect input!\ninput should be: ./philo \
[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] \
[number_of_times_each_philosopher_must_eat]");
	}
}
