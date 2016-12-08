/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:30:35 by lhamlyn           #+#    #+#             */
/*   Updated: 2016/12/08 12:49:48 by lhamlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		close_window(void)
{
	write(1, "Done!\n", 6);
	exit(0);
}

int		count_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		write(1, "Error reading from file\n", 24);
	while (get_next_line(fd, &line))
	{
		if (line)
			free(line);
		i++;
	}
	close(fd);
	return (i);
}

void	set_values(t_env *env)
{
	env->info.pos.x = 11;
	env->info.pos.y = 11;
	env->info.dir.x = -1;
	env->info.dir.y = 0;
	env->ray.plane.x = 0;
	env->ray.plane.y = 0.80;
}

void		init_info(t_env *env, char *str)
{
	int		i;
	int		fd;
	char	*map_name;
	char	**map;

	i = -1;
	map_name = str;
	env->map.y = count_lines(map_name);
	if ((fd = open(map_name, O_RDONLY)) == -1)
		write(1, "Error reading from file\n", 24);
	env->map.y = count_lines(map_name);
	if (!(map = (char **)malloc(sizeof(char *) * env->map.y + 1)))
		write(1, "Error assigning memory for map\n", 31);
	env->map.x = 0;
	while (++i < env->map.y)
	{
		if (get_next_line(fd, &map[i]) == -1)
			write(1, "Error reading map\n", 18);
		if ((int)ft_strlen(map[i]) > env->map.x)
			env->map.x = ft_strlen(map[i]);
	}
	set_values(env);
	env->map.map = map;
	close(fd);
}

int		main(int argc, char **argv)
{
	t_env	env;
	char	*str;

	str = NULL;
	if (argc != 2)
		str = "map";
	else
		str = argv[1];
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "Wolf3d");
	env.img.img = NULL;
	init_info(&env, str);
	mlx_loop_hook(env.mlx, &loop_hook, &env);
	if (env.mlx == NULL || env.win == NULL)
		exit(0);
	mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
	mlx_hook(env.win, 3, (1L << 1), &key_release, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_loop(env.mlx);
	return(0);
}
