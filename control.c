/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suyildiz <suyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:22:22 by suyildiz          #+#    #+#             */
/*   Updated: 2023/12/21 17:22:25 by suyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static int	ft_check_args(void)
{
	printf(" ____________________________________________________ \n");
	printf("|            Please enter 4 or 5 arguments           |\n");
	printf("|____________________________________________________|\n");
	printf("|             [1][Number of philosophers]            |\n");
	printf("|             [2][Time to die]                       |\n");
	printf("|             [3][Time to eat]                       |\n");
	printf("|             [4][Time to sleep]                     |\n");
	printf("|             [5][Number of meals]                   |\n");
	printf("|____________________________________________________|\n");
	return (0);
}

static int	input_ac_control(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_check_args());
	while (i < ac)
	{
		if (is_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_control(int ac, char **av)
{
	if (input_ac_control(ac, av) == 0)
		return (ft_err("Wrong Argument\n"));
	return (1);
}
