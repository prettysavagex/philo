/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:00 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 18:03:18 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_table *table)
{
	int	i;

	i = -1;
	if (table->t_count == table->n_of_philo)
	{
		while (++i < table->n_of_philo)
		{
			if (table->n_of_philo == 1)
				pthread_detach(table->philos[i].thread);
			if (pthread_join(table->philos[i].thread, NULL) != 0)
				pthread_detach(table->philos[i].thread);
		}
	}
	end_mutexes(table);
}

void	end_mutexes(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->stop_count);
	pthread_mutex_destroy(&table->count_eat);
	pthread_mutex_destroy(&table->eat_last);
	pthread_mutex_destroy(&table->is_die);
	pthread_mutex_destroy(&table->is_print);
	if (table->forks)
	{
		while (i < table->n_of_philo)
			pthread_mutex_destroy(&table->forks[i++]);
	}
	free (table->forks);
	free (table->philos);
	free (table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ft_control(ac, av) == 0)
		return (1);
	table = parse(ac, av);
	if (table != NULL)
	{
		table->retvalue = start_mutexes(table);
		if (table->retvalue < 5)
		{
			destroy_mutexes(table, table->retvalue);
			freeall(table, 3);
			ft_err("Mutex could not be created.\n");
			return (0);
		}
		if (table->n_of_philo > 0)
		{
			start_threads(table);
			end_threads(table);
		}
	}
	return (0);
}
