/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:29:26 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:21:29 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	argv_is_numeric(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_numeric(argv[i]))
		{
			printf("argv[i] : %s : is non numeric!\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	argv_is_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((ft_atoi(argv[i]) > INT_MAX) || (ft_atoi(argv[i]) < INT_MIN))
		{
			printf("argv[i] : %s : is out of int range!\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	check_inputs(int argc, char **argv)
{
	if (!argv_is_numeric(argc, argv))
		ft_error("[ERROR]: arguments non numeric\n");
	else if (!argv_is_int(argc, argv))
		ft_error("[ERROR]: arguments outside int range\n");
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		ft_error("[ERROR]: number of philos must be between 1 and 200.\n");
	else if (ft_atoi(argv[2]) <= 0)
		ft_error("[ERROR]: time to die must be greater than 0 ms.\n");
	else if (ft_atoi(argv[3]) <= 0)
		ft_error("[ERROR]: time to eat must be greater than 0 ms.\n");
	else if (ft_atoi(argv[4]) <= 0)
		ft_error("[ERROR]: time to sleep must be greater than 0 ms.\n");
	else if (argc == 6 && ft_atoi(argv[5]) <= 0)
		ft_error("[ERROR]: Meals required must be greater than 0.\n");
}

//initilize the structs s_state which defines the state of each philo
//ft_atoi(argv[0]) is the name of the app
void	initilize_struct(int argc, char **argv, t_state *philo_state)
{
	check_inputs(argc, argv);
	philo_state->philo_num = ft_atoi(argv[1]);
	philo_state->time_to_die = ft_atoi(argv[2]);
	philo_state->time_to_eat = ft_atoi(argv[3]);
	philo_state->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_state->meal_num_req = ft_atoi(argv[5]);
	else
	{
		philo_state->meal_num_req = -1;
	}
	philo_state->stop_flag = 0;
	philo_state->start_time = timefunction();
	pthread_mutex_init(&philo_state->print_mutex_rule, NULL);
}
