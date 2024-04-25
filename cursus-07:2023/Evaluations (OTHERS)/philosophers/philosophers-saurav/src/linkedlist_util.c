/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:22:03 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:22:12 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_philo **m_philosophers, char *error_msg)
{
	if (*m_philosophers)
		ft_free_list(*m_philosophers);
	write(2, "Error\n", 6);
	printf("%s", error_msg);
	exit(1);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst)
	{
		while (lst->right != NULL)
		{
			lst = lst->right;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new_philo)
{
	t_philo	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->right = new_philo;
			new_philo->left = last;
		}
		else
		{
			*lst = new_philo;
			new_philo->left = NULL;
		}
		new_philo->right = NULL;
	}
}
