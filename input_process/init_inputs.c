/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:13:53 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/04 17:30:33 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int init_inputs(int argc, char **argv)
{
	if (check_arg_range(argc) == 1)
		return (1);
	if (check_arg_number(argv) == 1)
		return (1);
	if (ft_isnum_valid(argc, argv)  == 1)
		return (1);
	return (0);
}
