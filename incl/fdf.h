/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:58:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/13 12:00:41 by mbotes           ###   ########.fr       */
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
	float			p_x;
	float			p_y;
	float			p_z;
	float			p_w;
	struct s_point	*right;
	struct s_point	*down;
}					t_point;

typedef struct		s_env
{
	void			*w_ptr;
	void			*mlx_ptr;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	int				t_x;
	int				t_y;
	t_point			*p;
	int				h;
	int				w;
	int				scale;
}					t_env;

t_point				*ft_makepoint(int x, int y, int z);
void				ft_appendlist(int x, int y, int z, t_point **list);
void				ft_drawline(t_env env, t_point *p1, t_point *p2);
void				ft_drawline_y(t_env env, t_point *p1, t_point *p2);
void				ft_draw_links(t_env env, t_point *ptr);
int					fdf_exit(t_env *x);
void				ft_fix(t_env env, t_point *ptr);
int					fdf_key(int key, t_env *env);
void				ft_multiply_m(t_point *p, float mat[4][4]);
void				ft_rotate_p_x(t_point *p, float a);
void				ft_rotate_p_y(t_point *p, float a);
void				ft_rotate_p_z(t_point *p, float a);
void				ft_rotate(t_env env, t_point *ptr);
t_point				*ft_init(int fd, t_env *env);
void				ft_reset(t_env *env);
void				ft_delete_list(t_point **head);

#endif
