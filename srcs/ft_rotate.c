/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:09:50 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/13 12:07:31 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_rotate(t_env env, t_point *p)
{
	if (p != NULL)
	{
		p->p_w = p->w;
		p->p_x = p->x;
		p->p_y = p->y;
		p->p_z = p->z;
		ft_fix(env, p);
		ft_rotate_p_x(p, env.rot_x * (M_PI / 180.0));
		ft_rotate_p_y(p, env.rot_y * (M_PI / 180.0));
		ft_rotate_p_z(p, env.rot_z * (M_PI / 180.0));
		p->p_x *= env.scale;
		p->p_y *= env.scale;
		if (p != NULL && p->right != NULL)
			ft_rotate(env, p->right);
	}
	if (p && p->down != NULL && p->x == 0)
		ft_rotate(env, p->down);
	if (!p->right && !p->down)
	{
		mlx_clear_window(env.mlx_ptr, env.w_ptr);
		ft_draw_links(env, env.p);
	}
}

void	ft_rotate_p_x(t_point *p, float a)
{
	float	mat[4][4];
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat[i][j] = 0;
	}
	mat[0][0] = 1;
	mat[1][1] = cos(-a);
	mat[1][2] = -sin(-a);
	mat[2][1] = sin(-a);
	mat[2][2] = cos(-a);
	mat[3][3] = 1;
	ft_multiply_m(p, mat);
}

void	ft_rotate_p_y(t_point *p, float a)
{
	float	mat[4][4];
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat[i][j] = 0;
	}
	mat[0][0] = cos(-a);
	mat[0][2] = sin(-a);
	mat[1][1] = 1;
	mat[2][0] = -sin(-a);
	mat[2][2] = cos(-a);
	mat[3][3] = 1;
	ft_multiply_m(p, mat);
}

void	ft_rotate_p_z(t_point *p, float a)
{
	float	mat[4][4];
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat[i][j] = 0;
	}
	mat[0][0] = cos(-a);
	mat[0][1] = -sin(-a);
	mat[1][0] = sin(-a);
	mat[1][1] = cos(-a);
	mat[2][2] = 1;
	mat[3][3] = 1;
	ft_multiply_m(p, mat);
}
