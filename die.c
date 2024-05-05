/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:22:28 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:22:29 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	must_eating_check(t_table *table)
{
	int	i;

	if (table->number_of_must_eat < 0)
		return (0);
	i = 0;
	while (i < table->n_of_philo)
	{
		pthread_mutex_lock(&table->count_eat);
		if (table->philos[i++].eat_count < table->number_of_must_eat)
		{
			pthread_mutex_unlock(&table->count_eat);
			return (0);
		}
		else
			pthread_mutex_unlock(&table->count_eat);
	}
	return (1);
}

int	check_die(t_table *table, int i)
{
	while (table->n_of_philo > 0)
	{
		i = -1;
		while (++i < table->n_of_philo)
		{
			pthread_mutex_lock(&table->eat_last);
			pthread_mutex_lock(&table->is_die);
			if ((current_time() - table->philos[i].last_eat)
				>= table->time_to_die)
			{
				print(&table->philos[i], DIE);
				pthread_mutex_lock(&table->stop_count);
				table->stop = 1;
				pthread_mutex_unlock(&table->stop_count);
				pthread_mutex_unlock(&table->eat_last);
				return (0);
			}
			else
				pthread_mutex_unlock(&table->eat_last);
			pthread_mutex_unlock(&table->is_die);
		}
		if (must_eating_check(table))
			break ;
	}
	return (1);
}

void	die_check(t_table *table)
{
	int	i;

	i = -1;
	if (table->t_count != table->n_of_philo)
		return ;
	if (!(check_die(table, i)))
		return ;
	pthread_mutex_lock(&table->stop_count);
	table->stop = 1;
	pthread_mutex_unlock(&table->stop_count);
}
