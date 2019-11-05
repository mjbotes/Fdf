/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:02:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/17 11:01:59 by mbotes           ###   ########.fr       */
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

void	ft_filecheck(char *str)
{
	char	*ptr;

	ptr = str;
	while (ft_strchr(ptr, '.') != NULL)
		ptr = ft_strchr(ptr, '.') + 1;
	if (!(ft_strequ(ptr, "fdf")))
	{
		ft_putendl("File is of wrong type. file must be an fdf file");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	int		fd;

	if (ac == 2)
	{
		ft_filecheck(av[1]);
		env.mlx_ptr = mlx_init();
		env.w_ptr = mlx_new_window(env.mlx_ptr, 2000, 1000, "FDF");
		fd = open(av[1], O_RDONLY);
		env.p = ft_init(fd, &env);
		ft_reset(&env);
		env.t_x = 1000;
		env.t_y = 500;
		ft_rotate(env, env.p);
		mlx_hook(env.w_ptr, 17, 0, fdf_exit, &env);
		mlx_hook(env.w_ptr, 2, 0, fdf_key, &env);
		mlx_loop(env.mlx_ptr);
	}
	return (0);
}
