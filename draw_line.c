/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:02:46 by lhamlyn           #+#    #+#             */
/*   Updated: 2016/12/08 15:13:46 by lhamlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_image_put_pixel(void *mlx, t_img *i, t_coordint p, t_col *c)
{
	/*if (i->e)
	{
		i->data[p.y * i->s + p.x * i->bpp / 8] = mlx_get_color_value(mlx, c->r);
		i->data[p.y * i->s + p.x * i->bpp / 8 + 1] = 
		mlx_get_color_value(mlx, c->g);
		i->data[p.y * i->s + p.x * i->bpp / 8 + 2] =
		mlx_get_color_value(mlx, c->b);
	}*/
//	else
//	{
		i->data[p.y * i->s + i->bpp / 8 * p.x] = mlx_get_color_value(mlx, c->b);
		i->data[p.y * i->s + i->bpp / 8 * p.x + 1] = 
		mlx_get_color_value(mlx, c->g);
		i->data[p.y * i->s + i->bpp / 8 * p.x + 2] = 
		mlx_get_color_value(mlx, c->r);
//	}
}

void		draw_line(t_env *env, int x, t_col *col)
{
	t_coordint	pixel;
	t_col		flrsky;

	pixel.x = x;
	env->img.data = mlx_get_data_addr(env->img.img,
			&env->img.bpp, &env->img.s, &env->img.e);
	set_col(&flrsky, 102, 178, 255);
	pixel.y = 0;
	while (pixel.y < env->ray.draw_s)
	{
		mlx_image_put_pixel(env, &(env->img), pixel, &flrsky);
		pixel.y++;
	}
	pixel.y = env->ray.draw_s;
	while (pixel.y < env->ray.draw_e)
	{
		mlx_image_put_pixel(env, &(env->img), pixel, col);
		pixel.y++;
	}
	set_col(&flrsky, 64 ,64 ,64);
	pixel.y = env ->ray.draw_e - 1;
	while (++pixel.y < WIN_Y)
		mlx_image_put_pixel(env, &(env->img), pixel, &flrsky);
}
