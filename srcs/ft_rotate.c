/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:09:50 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/22 09:15:40 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_rotate_x(t_point *p)
{
	if (p != NULL)
	{
		ft_rotate_p_x(p, 89);
		if (p->right != NULL)
			ft_rotate_x(p->right);
	}
	if (p->down != NULL && p->x == 0)
		ft_rotate_x(p->down);
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
	mat[1][2] = cos(-a);
	ft_multiply_m(p, mat);
}
