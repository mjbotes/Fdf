/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:22:51 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/20 13:49:00 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_point	ft_makepoint(int x, int y)
{
	t_point	*new;

	new = (t_point*)malloc(sizeof(struct s_point));
	new->x = x;
	new->y = y;
	return (*new);
}
