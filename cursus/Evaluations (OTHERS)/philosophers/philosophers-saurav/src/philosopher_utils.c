/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:23:27 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:23:31 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers(t_state *rule_state, t_philo **philosophers)
{
	int		i;
	t_philo	*prev_philo;
	t_philo	*first_philo;
	t_philo	*new_philo;

	i = 0;
	prev_philo = NULL;
	first_philo = NULL;
	while (i < rule_state->philo_num)
	{
		new_philo = malloc(sizeof(t_philo));
		set_new_philo(new_philo, rule_state, i);
		if (prev_philo)
		{
			prev_philo->right = new_philo;
			new_philo->left = prev_philo;
		}
		else
			first_philo = new_philo;
		prev_philo = new_philo;
		i++;
	}
	first_philo->left = prev_philo;
	prev_philo->right = first_philo;
	*philosophers = first_philo;
}

void	set_new_philo(t_philo *m_philo, t_state *rule_state, int i)
{
	m_philo->id = i;
	m_philo->meals_to_full = rule_state->meal_num_req;
	m_philo->last_eat_time = get_elapsed(rule_state);
	m_philo->status = 'T';
	m_philo->rules = rule_state;
	m_philo->is_full = 0;
	pthread_mutex_init(&m_philo->my_fork, NULL);
	pthread_mutex_init(&m_philo->is_alive, NULL);
}

void	print_philosophers(t_philo **m_philosophers, int philo_count)
{
	int		i;
	t_philo	*cur_philo;

	i = 0;
	cur_philo = *m_philosophers;
	while (i < philo_count)
	{
		ft_printbr();
		print_philo_state(cur_philo);
		cur_philo = cur_philo->right;
		i++;
	}
}

void	print_philo_state(t_philo *m_philo)
{
	printf("m_philo->index:%d\n", m_philo->id);
	printf("m_philo->last_ate:%lld\n", m_philo->last_eat_time);
	printf("m_philo->meals_til_full:%d\n", m_philo->meals_to_full);
	printf("m_philo->is_full:%d\n", m_philo->is_full);
	printf("m_philo->status:%c\n", m_philo->status);
	printf("m_philo->left :%p\n", m_philo->left);
	printf("m_philo->right :%p\n", m_philo->right);
	printf("m_philo->rules.philo_num :%d\n", m_philo->rules->philo_num);
	printf("m_philo->rules.time_to_die :%d\n", m_philo->rules->time_to_die);
	printf("m_philo->rules.time_to_eat :%d\n", m_philo->rules->time_to_eat);
	printf("m_philo->rules.time_to_sleep :%d\n", m_philo->rules->time_to_sleep);
	printf("m_philo->rules.stop_flag :%d\n", m_philo->rules->stop_flag);
	printf("m_philo->rules.mealnum_req :%d\n", m_philo->rules->meal_num_req);
}
