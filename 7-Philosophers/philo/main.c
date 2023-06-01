/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:50 by swillis           #+#    #+#             */
/*   Updated: 2022/07/19 14:12:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_vars *vars, int n, int reaper_err)
{
	int	err;
	int	i;

	err = 0;
	if ((vars->n != n) || (reaper_err))
	{
		i = -1;
		while (++i < vars->n)
		{
			pthread_mutex_lock(vars->philo[i].lock);
			vars->philo[i].is_alive = 0;
			pthread_mutex_unlock(vars->philo[i].lock);
		}
	}
	if (reaper_err == 0)
		if (pthread_join(vars->th_reap, NULL) != 0)
			err = 1;
	i = -1;
	while (++i < vars->n)
		if (pthread_join(vars->th[i], NULL) != 0)
			err = 2;
	return (err);
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n)
	{
		pthread_mutex_destroy(&vars->fk[i]);
		pthread_mutex_destroy(&vars->locks[i]);
	}
	pthread_mutex_destroy(&vars->printable);
	free(vars->fk);
	free(vars->locks);
	free(vars->th);
	free(vars->philo);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		n;
	int		philo_err;
	int		reaper_err;
	int		join_err;

	if (check_args(ac, av) != 0)
		return (1);
	if (init_vars(ac, av, &vars) != 0)
		return (2);
	if (init_mutexes(&vars, 0) != 0)
		return (3);
	n = vars.n;
	philo_err = init_philos(&vars);
	reaper_err = init_reaper(&vars);
	join_err = join_threads(&vars, n, reaper_err);
	vars.n = n;
	free_vars(&vars);
	if (philo_err)
		return (4);
	if (reaper_err)
		return (5);
	if (join_err)
		return (6);
	return (0);
}
