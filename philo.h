/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:18 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:23:20 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>

# define TAKEN_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING	"is sleeping"
# define IS_THINKING "is thinking"
# define DIE "died"

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	uint64_t		id;
	uint64_t		last_eat;
	uint64_t		last_sleep;
	int				eat_count;
	int				sleeping;
	int				eating;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				retvalue;
	int				t_count;
	int				n_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				stop;
	uint64_t		time_to_die;
	uint64_t		time;
	pthread_mutex_t	stop_count;
	pthread_mutex_t	count_eat;
	pthread_mutex_t	eat_last;
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_print;
	pthread_mutex_t	is_die;
}	t_table;

int				ft_control(int ac, char **av);

//utils
int				ft_atoi(char *str);
int				ft_err(char *str);
int				is_digit(char *str);
void			print(t_philo *philo, char *str);

//init
void			fork_init(t_philo *philo, t_table *table, int i);
int				philo_init(t_philo *philo, t_table *table, int i);
int				start_mutexes(t_table *table);
int				start_threads(t_table *table);
t_table			*arg_init(int ac, char **av, t_table *table);
//parse
t_table			*parse(int ac, char **av);
void			freeall(void *_table, int flag);

//routine
void			*philo_routine(void *_philo);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

//time
uint64_t		current_time(void);
uint64_t		time_from_start(t_table *table);
void			time_usleep(uint16_t micsec);

//die
int				check_die(t_table *table, int i);
void			die_check(t_table *table);
int				must_eating_check(t_table *table);

//destroy
void			destroy_mutexes(t_table *table, int mutex_count);
void			end_mutexes(t_table *table);
void			end_threads(t_table *table);

#endif
