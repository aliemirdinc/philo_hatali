/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:56:37 by aldinc            #+#    #+#             */
/*   Updated: 2025/02/06 17:28:03 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_arg_range(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("error, wrong argument number\n");
		return (1);
	}
	return (0);
}

static int	check_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int check_arg_number(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (check_number(argv[i]) == 1)
		{
			printf("Error: All arguments must be positive numbers.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isnum_valid(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
		return(printf("invalid philos number"), 1);
	if (ft_atoi(argv[2]) <= 0)
		return(printf("invalid philos time to die"), 1);
	if (ft_atoi(argv[3]) <= 0)
		return(printf("invalid philos time to eat"), 1);
	if (ft_atoi(argv[4]) <= 0)
		return(printf("invalid philos time to sleep"), 1);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return(printf("invalid num of each philo eat"), 1);
		if (ft_atoi(argv[5]) == 0)
			return(printf("invalid num of each philo eat"), 1);
	}
	return (0);
}
