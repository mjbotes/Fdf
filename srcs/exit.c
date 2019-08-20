/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:20:07 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 15:26:49 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	fdf_exit(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->w_ptr);
	exit(0);
	return (0);
}

int	fdf_key(int key, t_env *env)
{
	if (key == 53)
		fdf_exit(env);
	return (0);
}
