/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexdestroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:06 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:23:08 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_table *table, int mutex_count)
{
	if (mutex_count >= 1)
		pthread_mutex_destroy(&table->stop_count);
	if (mutex_count >= 2)
		pthread_mutex_destroy(&table->count_eat);
	if (mutex_count >= 3)
		pthread_mutex_destroy(&table->eat_last);
	if (mutex_count >= 4)
		pthread_mutex_destroy(&table->is_print);
}
