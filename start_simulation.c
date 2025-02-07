/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:04:26 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/06 14:49:10 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_simulation(t_simulation *sim, t_philosopher *philos)
{
	int i;

	i = 0;
	while (i < sim->philo_num)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine, (void *)&philos[i]) != 0)
		{
			// Hata durumunda uygun temizlik yapılmalı
			return;
		}
		i++;
	}
	pthread_create(&sim->sim_over_check, NULL, death_monitor, (void *)philos);
	// Burada ayrı bir death-monitor (ölüm izleyici) thread'i oluşturup, filozofların ölüm zamanlarını kontrol edebilirsin.
	// Örneğin: create_monitor_thread(sim, philos);
	pthread_join(sim->sim_over_check, NULL);
	i = 0;
	while (i < sim->philo_num)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
