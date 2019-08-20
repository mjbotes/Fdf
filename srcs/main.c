/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:02:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 15:33:15 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		main(void)
{
	t_env	env;
	t_point	p1;
	t_point p2;

	p1 = ft_makepoint(0, 300);
	p2 = ft_makepoint(250, 250);
	env.mlx_ptr = mlx_init();
	env.w_ptr = mlx_new_window(env.mlx_ptr, 500, 500, "FDF");
	ft_drawline(env, p1, p2);
	mlx_hook(env.w_ptr, 17, 0, fdf_exit, &env);
	mlx_hook(env.w_ptr, 2, 0, fdf_key, &env);
	mlx_loop(env.mlx_ptr);
}
