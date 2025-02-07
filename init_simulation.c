/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:39:23 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/06 15:29:00 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_simulation *init_simulation(int argc, char **argv)
{
	t_simulation *sim;
	int i;

	sim = malloc(sizeof(t_simulation));
	if (!sim)
		return (NULL);
	sim->philo_num = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	sim->num_of_eat = 0;
	if (argc == 6)
		sim->num_of_eat = ft_atoi(argv[5]);
	
	sim->simulation_over = 0;
	sim->start_time = get_time_in_ms();

	// Fork mutex dizisini oluştur
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->philo_num);
	if (!sim->forks)
		return (NULL);
	i = 0;
	while (i < sim->philo_num)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
		{
			// Hata durumunda burada temizleme işlemleri yapmalısın
			return (NULL);
		}
		i++;
	}
	// Log mutex'ini başlat
	if (pthread_mutex_init(&sim->log_mutex, NULL) != 0)
		return (NULL);
	return (sim);
}
