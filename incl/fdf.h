/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:58:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 15:28:02 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_env
{
	void		*w_ptr;
	void		*mlx_ptr;
}				t_env;

t_point			ft_makepoint(int x, int y);
void			ft_drawline(t_env env, t_point p1, t_point p2);
void			ft_drawline_y(t_env env, t_point p1, t_point p2);
int				fdf_exit(t_env *x);
int				fdf_key(int key, t_env *x);

#endif
