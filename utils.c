/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:23:36 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:23:38 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_err(char *str)
{
	printf("%s", str);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void	print(t_philo *philo, char *str)
{
	uint64_t	i;

	i = time_from_start(philo->table);
	pthread_mutex_lock(&philo->table->is_print);
	pthread_mutex_lock(&philo->table->stop_count);
	if (!philo->table->stop)
		printf("\033[0;35m%llu \033[0;33m%llu %s\033[0m\n", i, philo->id, str);
	pthread_mutex_unlock(&philo->table->stop_count);
	pthread_mutex_unlock(&philo->table->is_print);
}
