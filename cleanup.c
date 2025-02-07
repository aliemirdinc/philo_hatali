/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:09:55 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/04 19:10:27 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup(t_simulation *sim, t_philosopher *philos)
{
    int i = 0;
    while (i < sim->philo_num)
    {
        pthread_mutex_destroy(&sim->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&sim->log_mutex);
    free(sim->forks);
    free(philos);
    free(sim);
}
