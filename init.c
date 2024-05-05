/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:22:33 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:22:35 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_mutexes(t_table *table)
{
	int	mutex_count;

	mutex_count = 0;
	if (pthread_mutex_init(&table->stop_count, NULL) == 0)
		mutex_count++;
	if (mutex_count == 1 && pthread_mutex_init(&table->count_eat, NULL) == 0)
		mutex_count++;
	if (mutex_count == 2 && pthread_mutex_init(&table->eat_last, NULL) == 0)
		mutex_count++;
	if (mutex_count == 3 && pthread_mutex_init(&table->is_print, NULL) == 0)
		mutex_count++;
	if (mutex_count == 4 && pthread_mutex_init(&table->is_die, NULL) == 0)
		mutex_count++;
	return (mutex_count);
}

int	philo_init(t_philo *philo, t_table *table, int i)
{
	static int	x;

	philo->id = i + 1;
	philo->table = table;
	philo->eat_count = 0;
	philo->last_eat = current_time();
	if (pthread_mutex_init(&table->forks[i], NULL) == 0)
		x++;
	else
	{
		while (x >= 0)
		{
			if (x == 0)
				return (0);
			pthread_mutex_destroy(&table->forks[x--]);
		}
	}
	return (1);
}

void	fork_init(t_philo *philo, t_table *table, int i)
{
	if (i == 0)
		philo->rfork = table->forks + (table->n_of_philo - 1);
	else
		philo->rfork = &table->forks[i - 1];
	philo->lfork = &table->forks[i];
}

int	start_threads(t_table *table)
{
	int	i;

	table->t_count = 0;
	i = -1;
	while (++i < table->n_of_philo)
		if (philo_init(&table->philos[i], table, i) == 0)
			return (ft_err("Mutex could not be created.\n"), 0);
	i = -1;
	while (++i < table->n_of_philo)
		fork_init(&table->philos[i], table, i);
	i = -1;
	while (++i < table->n_of_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_routine, table->philos + i) != 0)
		{
			ft_err("Thread could not be created.\n");
			break ;
		}
		table->t_count++;
	}
	die_check(table);
	return (1);
}
