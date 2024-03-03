/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:30 by atang             #+#    #+#             */
/*   Updated: 2024/03/03 18:10:10 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//t_data	data;
	(void)	argv;

	if (argc == 5 || argc == 6)
	{
		/*
		parse_input;
		init_data;
		start_dinner;
		clean;
		*/
	}
	else
	{
		error_and_exit("Incorrect input!\nCorrect format is: ./philo " \
					"[number_of_philosophers] [time_to_die] [time_to_eat] " \
					"[time_to_sleep] (optional)[number_of_times_each_philosopher_must_eat]");
	}
}
