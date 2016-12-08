/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:41:24 by lhamlyn           #+#    #+#             */
/*   Updated: 2016/12/08 12:43:42 by lhamlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_fps(t_env *env)
{
	struct timeval	time;

	env->o_time = env->time;
	gettimeofday(&time, 0);
	env->time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	env->f_time = env->time - env->o_time;
	env->info.m_speed = env->f_time * 0.004;
	env->info.r_speed = env->f_time * 0.004;
}
