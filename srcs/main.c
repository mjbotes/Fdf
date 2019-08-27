/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:02:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/26 09:06:25 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_reset(t_env *env)
{
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->scale = 10;
}

int		main(int ac, char **av)
{
	t_env	env;
	int		fd;

	env.mlx_ptr = mlx_init();
	env.w_ptr = mlx_new_window(env.mlx_ptr, 2000, 1000, "FDF");
	fd = open(av[ac - 1], O_RDONLY);
	env.p = ft_init(fd, &env);
	ft_reset(&env);
	env.t_x = 1000;
	env.t_y = 500;
	ft_rotate(env, env.p);
	mlx_hook(env.w_ptr, 17, 0, fdf_exit, &env);
	mlx_hook(env.w_ptr, 2, 0, fdf_key, &env);
	mlx_loop(env.mlx_ptr);
}
