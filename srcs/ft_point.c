/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:22:51 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/13 11:59:18 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_point		*ft_makepoint(int x, int y, int z)
{
	t_point	*new;

	new = (t_point*)malloc(sizeof(struct s_point));
	new->x = x;
	new->y = y;
	new->z = z;
	new->w = 1;
	new->p_x = x;
	new->p_y = y;
	new->p_z = z;
	new->p_w = 1;
	new->right = NULL;
	new->down = NULL;
	return (new);
}

static void	ft_addtolist(t_point **head, t_point *new)
{
	t_point	*ptr;

	ptr = *head;
	while (ptr->down && ptr->down->down != NULL)
		ptr = ptr->down;
	while (ptr->down && ptr->right && ptr->down->right)
		ptr = ptr->right;
	if (ptr->down)
		ptr->down->right = new;
	if (ptr->right)
		ptr->right->down = new;
}

void		ft_appendlist(int x, int y, int z, t_point **list)
{
	t_point	*ptr;
	t_point	*new;

	new = ft_makepoint(x, y, z);
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	ptr = *list;
	if (x == 0)
	{
		while (ptr->down)
			ptr = ptr->down;
		ptr->down = new;
	}
	else if (y == 0)
	{
		while (ptr->right)
			ptr = ptr->right;
		ptr->right = new;
	}
	else
		ft_addtolist(list, new);
}

void		ft_delete_node(t_point *ptr)
{
	free(ptr);
	ptr = NULL;
}

void		ft_delete_list(t_point **head)
{
	t_point *ptr;

	while (*head)
	{
		ptr = *head;
		while (ptr->down && ptr->down->right)
			ptr = ptr->down;
		if (ptr->down && !ptr->down->right)
		{
			ft_delete_node(ptr->down);
			ptr->down = NULL;
		}
		else if (!ptr->down && ptr->right)
		{
			while (ptr->right->right)
				ptr = ptr->right;
			ft_delete_node(ptr->right);
			ptr->right = NULL;
		}
		else
		{
			ft_delete_node(*head);
			*head = NULL;
		}
	}
}
