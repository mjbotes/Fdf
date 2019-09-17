/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:54:45 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/13 11:57:14 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_point	*ft_init(int fd, t_env *env)
{
	char	**arr;
	char	*str;
	int		loop;
	t_point	*list;

	env->w = -1;
	list = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		loop = -1;
		arr = ft_strsplit(str, ' ');
		ft_strdel(&str);
		while (arr[++loop] != NULL)
			ft_appendlist(loop, env->h, ft_atoi(arr[loop]), &list);
		ft_free_her(arr);
		if (env->w == -1)
			env->w = loop;
		else if (loop != env->w)
		{
			ft_putendl("Map is invalid");
			fdf_exit(env);
		}
		env->h++;
	}
	return (list);
}

void	ft_fix(t_env env, t_point *ptr)
{
	ptr->p_x = ptr->x - env.w / 2;
	ptr->p_y = ptr->y - env.h / 2;
}
