/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:45:58 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:22:27 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_routine(t_philo *m_philo)
{
	int	n;
	int	i;

	n = m_philo->rules->philo_num;
	i = 0;
	while (i < n)
	{
		pthread_join(m_philo->thread_id, NULL);
		m_philo = m_philo->right;
		i++;
	}
}

void	cleanup_routine(t_philo *m_philo)
{
	int	n;
	int	i;

	i = 0;
	n = m_philo->rules->philo_num;
	while (i < n)
	{
		pthread_mutex_destroy(&(m_philo->my_fork));
		pthread_mutex_unlock(&(m_philo->is_alive));
		pthread_mutex_destroy(&(m_philo->is_alive));
		m_philo = m_philo->right;
		i++;
	}
	pthread_mutex_destroy(&m_philo->rules->print_mutex_rule);
	ft_free_list(m_philo);
}

void	ft_free_list(t_philo *first)
{
	t_philo	*cur_philo;
	t_philo	*next_philo;
	t_philo	*temp;
	int		n;
	int		i;

	cur_philo = first;
	n = first->rules->philo_num;
	i = 0;
	while (i < n)
	{
		temp = cur_philo;
		next_philo = cur_philo->right;
		free(temp);
		cur_philo = next_philo;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_state		rule_state;
	t_philo		*philosophers;
	pthread_t	mthread_id;

	if (argc > 6 || argc < 5)
	{
		printf ("Invalid arguments \n");
		return (1);
	}
	initilize_struct(argc, argv, &rule_state);
	init_philosophers(&rule_state, &philosophers);
	run_routine(philosophers);
	if (pthread_create(&mthread_id, NULL, ft_run_monitor, philosophers) != 0)
		print_status(philosophers, 'X');
	pthread_join(mthread_id, NULL);
	close_routine(philosophers);
	cleanup_routine(philosophers);
	return (0);
}
