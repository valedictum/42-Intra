/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:19:49 by pchawda           #+#    #+#             */
/*   Updated: 2024/05/11 23:34:06 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_check_args(t_table *table, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("\033[33m<number_of_philosophers>\n<time:die>\033[0m");
		printf("\033[33m\n<time:eat>\n<time:sleep>\n<no.philo_eat>\n\033[0m");
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!digit_check(argv[i]))
		{
			printf("Arguments need to be represented as integers\n");
		}
		if (is_int(argv[i]) <= 0)
		{
			printf("Arguments need to be greater than 0\n");
		}
		i++;
	}
	set_arguments(table, argc, argv);
	if (error_message_args(table) == EXIT_FAILURE)
		return (free(table), EXIT_FAILURE);
	return (0);
}

void	set_arguments(t_table *table, int argc, char **argv)
{
	table -> philos_num = atoi_philo(argv[1]);
	table -> time_to_die = atoi_philo(argv[2]);
	table -> time_to_eat = atoi_philo(argv[3]);
	table -> time_to_sleep = atoi_philo(argv[4]);
	if (argc == 6)
	{
		table -> eat_x_times = atoi_philo(argv[5]);
		if (argv[5] && table -> eat_x_times < 0)
			printf("\033[1;91mThe number of meals cannot be negative\033[0m\n");
	}
	else
		table -> eat_x_times = 0;
}

int	error_message_args(t_table *table)
{
	if (table -> philos_num < 1)
	{
		printf("There has to be least 1 philo\n");
		return (EXIT_FAILURE);
	}
	if (table -> time_to_die <= 0)
	{
		printf("The time_to_die has to be greater than 0\n");
		return (EXIT_FAILURE);
	}
	if (table -> time_to_eat <= 0)
	{
		printf("The time_to_eat has to be greater than 0\n");
		return (EXIT_FAILURE);
	}
	if (table -> time_to_sleep <= 0)
	{
		printf("The time_to_sleep has to be greater than 0\n");
		return (EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (set_check_args(table, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all(table) == -1)
		return (EXIT_FAILURE);
	control(table, table -> philos);
	wait_threads(table);
	destroy(table);
	free_all(table);
}
