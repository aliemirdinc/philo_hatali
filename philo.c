/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:26:35 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/07 11:47:06 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_simulation	*sim;
	t_philosopher	*philos;

	if (init_inputs(argc, argv) == 1)
		return (1);
	sim = init_simulation(argc, argv);
	if (!sim)
	{
		printf("Error initializing simulation.\n");
		return (0);
	}
	philos = init_philosophers(sim);
	if (!philos)
	{
		printf("Error initializing philosophers.\n");
		// sim'i ve mutex'leri serbest bırakmayı unutma
		free(sim);
		return (1);
	}
	if (check_one(philos) == 1)
		return (1);
	// Filozof thread'lerini başlat
	start_simulation(sim, philos);

	// Temizlik işlemleri
	cleanup(sim, philos);

	return (0);
}
