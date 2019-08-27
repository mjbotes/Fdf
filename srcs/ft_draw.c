/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:32:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/26 14:14:28 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_point	*ft_init(int fd, t_env *env)
{
	char	**arr;
	char	*str;
	int		loop;
	int		y;
	t_point	*list;

	y = 0;
	env->w = 0;
	list = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		loop = -1;
		arr = ft_strsplit(str, ' ');
		while (arr[++loop] != NULL)
		{
			ft_appendlist(loop, y, ft_atoi(arr[loop]), &list);
		}
		if (loop > env->w)
			env->w = loop;
		y++;
	}
	env->h = y;
	return (list);
}

void	ft_fix(t_env env, t_point *ptr)
{
	ptr->p_x = ptr->x - env.w / 2;
	ptr->p_y = ptr->y - env.h / 2;
}

void	ft_draw_links(t_env env, t_point *ptr)
{
	if (ptr->right != NULL)
	{
		ft_drawline(env, ptr, ptr->right);
		ft_draw_links(env, ptr->right);
	}
	if (ptr->down != NULL)
	{
		ft_drawline(env, ptr, ptr->down);
		if (ptr->x == 0)
			ft_draw_links(env, ptr->down);
	}
}

void	ft_drawline(t_env env, t_point *p1, t_point *p2)
{
	int		x;
	int		y;
	float	diff;
	t_point	start;
	t_point	end;

	x = (p1->p_x - p2->p_x);
	start = *p2;
	end = *p1;
	if (x < 0)
	{
		start = *p1;
		end = *p2;
		x *= -1;
	}
	y = start.p_y;
	diff = (end.p_y - start.p_y);
	if (x != 0 && (diff /= x) <= 0.5)
		while (--x >= 0)
			mlx_pixel_put(env.mlx_ptr, env.w_ptr, start.p_x + x +
				env.t_x, y + (diff * x) + env.t_y, 0xffffff);
	ft_drawline_y(env, p1, p2);
}

void	ft_drawline_y(t_env env, t_point *p1, t_point *p2)
{
	int		x;
	int		y;
	float	diff;
	t_point	start;
	t_point	end;

	y = (p1->p_y - p2->p_y);
	start = *p2;
	end = *p1;
	if (y < 0)
	{
		start = *p1;
		end = *p2;
		y *= -1;
	}
	x = start.p_x;
	diff = (end.p_x - start.p_x);
	diff /= y;
	while (--y >= 0)
		mlx_pixel_put(env.mlx_ptr, env.w_ptr, x + (diff * y) + env.t_x,
			start.p_y + y + env.t_y, 0xffffff);
}
