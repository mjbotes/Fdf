/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:20:07 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/13 12:09:49 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		fdf_exit(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->w_ptr);
	ft_delete_list(&env->p);
	exit(0);
	return (0);
}

void	ft_keys(int key, t_env *env)
{
	if (key == 15)
		env->rot_z += 10;
	else if (key == 3)
		env->rot_z -= 10;
	else if (key == 125)
		env->t_y += env->h / 10 * env->scale;
	else if (key == 126)
		env->t_y -= env->h / 10 * env->scale;
	else if (key == 124)
		env->t_x += env->w / 10 * env->scale;
	else if (key == 123)
		env->t_x -= env->w / 10 * env->scale;
	else if (key == 24 && env->scale != 320)
		env->scale *= 2;
	else if (key == 27 && env->scale != 1)
		env->scale /= 2;
	else if (key == 49)
		ft_reset(env);
}

int		fdf_key(int key, t_env *env)
{
	if (key == 53)
		fdf_exit(env);
	else if (key == 13)
		env->rot_x += 10;
	else if (key == 1)
		env->rot_x -= 10;
	else if (key == 2)
		env->rot_y += 10;
	else if (key == 0)
		env->rot_y -= 10;
	else
		ft_keys(key, env);
	ft_rotate(*env, env->p);
	return (0);
}
