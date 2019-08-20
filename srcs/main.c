/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:02:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 15:30:12 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_drawline(t_env env, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	diff;
	t_point	start;
	t_point	end;

	x = p1.x - p2.x;
	start = p2;
	end = p1;
	if (x < 0)
	{
		start = p1;
		end = p2;
		x *= -1;
	}
	y = start.y;
	diff = end.y - start.y;
	if (x != 0 && (diff /= x) <= 0.5)
		while (--x > 0)
			mlx_pixel_put(env.mlx_ptr, env.w_ptr, start.x + x, y +
				(diff * x), 0xffffff);
	else
		ft_drawline_y(env, p1, p2);
}

void	ft_drawline_y(t_env env, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	diff;
	t_point	start;
	t_point	end;

	y = p1.y - p2.y;
	start = p2;
	end = p1;
	if (y < 0)
	{
		start = p1;
		end = p2;
		y *= -1;
	}
	x = start.x;
	diff = end.x - start.x;
	diff /= y;
	while (--y > 0)
		mlx_pixel_put(env.mlx_ptr, env.w_ptr, x + (diff * y),
			start.y + y, 0xffffff);
}

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
