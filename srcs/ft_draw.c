/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:32:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 15:33:28 by mbotes           ###   ########.fr       */
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
