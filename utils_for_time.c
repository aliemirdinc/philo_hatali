/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:36:19 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/08 16:31:20 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_time_in_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

 int	ft_usleep(size_t milliseconds, t_simulation *sim)
{
 	size_t	start;
 	start = get_time_in_ms();
 	while ((get_time_in_ms() - start) < milliseconds
 		&& sim->simulation_over == 0)
 		usleep(1000);
 	return (0);
}

void	*death_monitor(void *monitor)
{
	t_philosopher	*philo;
	int		i;
	int		j;
	size_t	s;

	philo = (t_philosopher *)monitor;
	i = 0;
	while(1)
	{
		i = 0;
		while (i < philo->sim->philo_num)
		{
			s = get_time_in_ms() - philo[i].last_meal;
			if (s >= philo[i].sim->time_to_die && philo[i].eat_check != 1)
			{
				philo[i].sim->simulation_over = 1;
				pthread_mutex_lock(&philo->sim->log_mutex);
				printf("%ld %d died\n", get_time_in_ms() - philo[i].sim->start_time, philo[i].id);
				pthread_mutex_unlock(&philo->sim->log_mutex);
				return (NULL);
			}
			i++;
		}
		i = 0;
		if (philo[i].sim->num_of_eat != 0)
		{
			j = 0;
			while (i < philo->sim->philo_num)
			{
				if (philo[i].eat_check == 1)
					j++;
				i++;
			}
			if (j == philo->sim->philo_num)
				return (NULL);
		}
	}
}

void	ft_printf(t_philosopher *philo, char *message)
{
	if (philo->sim->simulation_over == 0)
	{
		pthread_mutex_lock(&philo->sim->log_mutex);
        printf("%ld %d %s\n", get_time_in_ms() - philo->sim->start_time, \
					philo->id + 1, message);
    	pthread_mutex_unlock(&philo->sim->log_mutex);
	}
}
