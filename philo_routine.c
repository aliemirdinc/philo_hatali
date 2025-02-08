/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:02:21 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/08 18:46:16 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_one(t_philosopher *philo)
{
	int i;

	i = 0;
	if (philo->sim->philo_num == 1)
	{
		ft_printf(philo, "has taken a fork");
		ft_printf(philo, "died");
		i = 1;
	}
	return (i);
}

static void	take_fork(int left, int right,t_philosopher *philo, t_simulation *sim)
{
	if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(&sim->forks[left]);
			pthread_mutex_lock(&sim->forks[right]);
		}
	else
		{
			pthread_mutex_lock(&sim->forks[right]);
			pthread_mutex_lock(&sim->forks[left]);
		}
}

static void	leave_fork(int left, int right,t_philosopher *philo, t_simulation *sim)
{
	if (philo->id % 2 == 1)
		{
			pthread_mutex_unlock(&sim->forks[left]);
			pthread_mutex_unlock(&sim->forks[right]);
		}
	else
		{
			pthread_mutex_unlock(&sim->forks[right]);
			pthread_mutex_unlock(&sim->forks[left]);
		}
}

void *philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;
	t_simulation  *sim = philo->sim;

	if (check_one(philo) == 1)
		return (NULL);

	while (!sim->simulation_over)
	{
		int left = philo->id;
		int right = (philo->id + 1) % sim->philo_num;

		// Düşünme
		ft_printf(philo, "is thinking");

		// Deadlock riskini azaltmak için asime trik kilitleme örneği
		take_fork(left, right, philo, sim);
		philo->last_meal = get_time_in_ms();

		// Çatal alma log'u (iki çatal alındığı için iki mesaj)
		ft_printf(philo, "has taken a fork");
		ft_printf(philo, "has taken a fork");
		ft_printf(philo, "is eating");

		// Yemek yeme süresince bekle
		ft_usleep(sim->time_to_eat, sim);
		philo->meals_eaten++;

		if (philo->sim->num_of_eat != 0)
		{
			if (philo->meals_eaten == philo->sim->num_of_eat)
			{
				philo->eat_check = 1;
				leave_fork(left, right, philo, sim);
				return (NULL);
			}
		}
		// Çatal bırakma: önce aldığın sırayı bozmayacak şekilde kilitleri aç
		leave_fork(left, right, philo, sim);

		// Uyuma
		ft_printf(philo, "is sleeping");
		ft_usleep(sim->time_to_sleep, sim);
	}
	return (NULL);
}
