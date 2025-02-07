/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:08:08 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/06 17:40:49 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher *init_philosophers(t_simulation *sim)
{
	t_philosopher *philos;
	int i;

	philos = malloc(sizeof(t_philosopher) * sim->philo_num);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < sim->philo_num)
	{
		philos[i].id = i;
		philos[i].eat_check = 0;
		philos[i].meals_eaten = 0;
		philos[i].sim = sim;
		philos[i].last_meal = sim->start_time;
		i++;
	}
	return (philos);
}
