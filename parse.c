/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:11 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:23:13 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freeall(void *_table, int flag)
{
	t_table	*table;

	table = (t_table *) _table;
	if (flag == 1)
		free(table);
	if (flag == 2)
	{
		free(table->philos);
		free(table);
	}
	if (flag == 3)
	{
		free(table->forks);
		free(table->philos);
		free(table);
	}
}

t_table	*arg_init(int ac, char **av, t_table *table)
{
	table->n_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->number_of_must_eat = -1;
	if (ac == 6)
		table->number_of_must_eat = ft_atoi(av[5]);
	return (table);
}

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table = arg_init(ac, av, table);
	table->philos = malloc(sizeof(t_philo) * table->n_of_philo);
	if (!table->philos)
	{
		freeall(table, 1);
		return (NULL);
	}
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_of_philo);
	if (!table->forks)
	{
		freeall(table, 2);
		return (NULL);
	}
	table->time = current_time();
	table->stop = 0;
	return (table);
}
