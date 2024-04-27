/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:51:47 by sentry            #+#    #+#             */
/*   Updated: 2024/04/27 09:58:20 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    SPINLOCK to synchronize philos start
*/

void    wait_all_threads(t_data *data)
{
    while(!get_bool(&data->table_mutex, &data->all_threads_ready))
        ;
}
