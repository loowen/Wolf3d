/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:16:07 by lhamlyn           #+#    #+#             */
/*   Updated: 2016/12/08 12:50:21 by lhamlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	turn(t_env *env, char dir)
{
	double	temp_dir;
	double	temp_plane;
	int		sign;

	sign = 1;
	if (dir == 'r')
		sign = -1;
	temp_dir = env->info.dir.x;
	temp_plane = env->ray.plane.x;
	env->info.dir.x = env->info.dir.x * cos(sign * env->info.r_speed)
		- env->info.dir.y * sin(sign * env->info.r_speed);
	env->info.dir.y = temp_dir * sin(sign * env->info.r_speed)
		+ env->info.dir.y * cos(sign * env->info.r_speed);
	env->ray.plane.x = env->ray.plane.x * cos(sign * env->info.r_speed)
		- env->ray.plane.y * sin(sign * env->info.r_speed);
	env->ray.plane.y = temp_plane * sin(sign * env->info.r_speed)
		+ env->ray.plane.y * cos(sign * env->info.r_speed);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == LEFT)
		env->info.move.left = 1;
	if (keycode == UP)
		env->info.move.up = 1;
	if (keycode == RIGHT)
		env->info.move.right = 1;
	if (keycode == DOWN)
		env->info.move.down = 1;
	return (0);
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		write(1, "Done!\n", 6);
		exit(0);
	}
	if (keycode == LEFT)
		env->info.move.left = 0;
	if (keycode == UP)
		env->info.move.up = 0;
	if (keycode == RIGHT)
		env->info.move.right = 0;
	if (keycode == DOWN)
		env->info.move.down = 0;
	return (0);
}

void		move_up(t_env *env)
{
	if (env->info.move.up)
	{
		if (!(env->map.map[(int)(env->info.pos.x + env->info.dir.x
			* env->info.m_speed)][(int)(env->info.pos.y)] == '*'))
			env->info.pos.x += env->info.dir.x * env->info.m_speed;
		if (!(env->map.map[(int)(env->info.pos.x)][(int)(env->info.pos.y
			+ env->info.dir.y * env->info.m_speed)] == '*'))
			env->info.pos.y += env->info.dir.y * env->info.m_speed;
	}
}

void		move_player(t_env *env)
{
	move_up(env);
	if (env->info.move.left)
		turn(env, 'l');
	if (env->info.move.right)
		turn(env, 'r');
	if (env->info.move.down)
	{
		if (!(env->map.map[(int)(env->info.pos.x - env->info.dir.x
			* env->info.m_speed)][(int)(env->info.pos.y)] == '*'))
			env->info.pos.x -= env->info.dir.x * env->info.m_speed;
		if (!(env->map.map[(int)(env->info.pos.x)]
			[(int)(env->info.pos.y - env->info.dir.y
			* env->info.m_speed)] == '*'))
		env->info.pos.y -= env->info.dir.y * env->info.m_speed;
	}
}
