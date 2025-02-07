#ifndef PHILO
# define PHILO

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_simulation
{
	int				philo_num;
	unsigned long	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	long			start_time;
	int				simulation_over;
	pthread_t		sim_over_check;
	pthread_mutex_t	*forks;         // Filozof sayısı kadar mutex (çatal)
	pthread_mutex_t	log_mutex;      // Log mesajlarının karışmaması için
}	t_simulation;

typedef struct s_philosopher
{
	int             id;
	long            last_meal;
	int             meals_eaten;
	int				eat_check;
	t_simulation    *sim;
	pthread_t       thread;
}	t_philosopher;

//control input functs
int		check_arg_range(int argc);
int		check_arg_number(char **argv);
int		ft_isnum_valid(int argc, char **argv);
int		init_inputs(int argc, char **argv);

void cleanup(t_simulation *sim, t_philosopher *philos);

t_philosopher *init_philosophers(t_simulation *sim);

t_simulation *init_simulation(int argc, char **argv);

void *philosopher_routine(void *arg);

void start_simulation(t_simulation *sim, t_philosopher *philos);

size_t get_time_in_ms(void);

//utils functions
int	ft_atoi(const char *str);

int	ft_usleep(size_t milliseconds, t_simulation *sim);

void	*death_monitor(void *monitor);

void	ft_printf(t_philosopher *philo, char *message);

int	check_one(t_philosopher *philo);


#endif