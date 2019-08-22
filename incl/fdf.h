/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:58:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/21 13:26:38 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				w;
	int				p_x;
	int				p_y;
	int				p_z;
	int				p_w;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct	s_env
{
	void		*w_ptr;
	void		*mlx_ptr;
}				t_env;

t_point			*ft_makepoint(int x, int y, int z);
void			ft_appendlist(int x, int y, int z, t_point **list);
void			ft_drawline(t_env env, t_point *p1, t_point *p2);
void			ft_drawline_y(t_env env, t_point *p1, t_point *p2);
void			ft_draw_links(t_env env, t_point *ptr);
t_point			*ft_draw(int fd, t_env env);
int				fdf_exit(t_env *x);
int				fdf_key(int key, t_env *x);
void			ft_multiply_m(t_point *p, float mat[4][4]);
void			ft_rotate_p_x(t_point *p, float a);
void			ft_rotate_x(t_point *p);
t_point	*ft_init(int fd, t_env env);

#endif
