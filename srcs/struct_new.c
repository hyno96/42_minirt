/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:51:32 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 16:56:38 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "vec3.h"
#include "float.h"

t_sphere	*new_sphere(t_vec3 origin, t_float radius, t_color3 color)
{
	t_sphere *rtn;

	rtn = malloc(sizeof(t_sphere));
	rtn->origin = origin;
	rtn->radius = radius;
	rtn->surf.color = color;
}

t_plane	*new_plane(t_vec3 origin, t_vec3 normal, t_color3 color)
{
	t_plane *rtn;

	rtn = malloc(sizeof(t_plane));
	rtn->origin = origin;
	rtn->normal = normal;
	rtn->surf.color = color;
}

t_dot_light	*new_dot_light(t_vec3 origin, t_float radius, int color)
{
	t_dot_light *rtn;

	rtn = malloc(sizeof(t_dot_light));
	rtn->origin = origin;
	rtn->color.x = color;
	rtn->color.y = color;
	rtn->color.z = color;
}

t_list	*ft_lstnew_type(void *content, int type)
{
	t_list	*rtn;
	rtn->content = content;
	rtn->next = 0;
	rtn->type = type;
	return (rtn);
}