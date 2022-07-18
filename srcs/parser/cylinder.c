/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:55:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/18 18:28:50 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"
#include "libft.h"

static t_bool	modify_cylinder_args(t_cylinder_tmp_content *cy_content, \
										t_data *data)
{
	t_cylinder	*cy;
	t_list		*list;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (FALSE);
	cy->origin = vec3(cy_content->points[0], cy_content->points[1], \
						cy_content->points[2]);
	cy->normal = vec3(cy_content->normals[0], cy_content->normals[1], \
						cy_content->normals[2]);
	if (!check_normal(cy->normal))
	{
		free(cy);
		return (FALSE);
	}
	cy->normal = vec3_unit(cy->normal);
	cy->radius = (t_float)(cy_content->diameter / 2.0);
	cy->height = cy_content->height;
	cy->surf.color = vec3(cy_content->colors[0], cy_content->colors[1], \
							cy_content->colors[2]);
	list = ft_lstnew((void *)cy);
	list->type = CY;
	ft_lstadd_back(&(data->object_list), list);
	return (TRUE);
}

static t_bool	set_cylinder(char **args, t_data *data)
{
	t_float	points[3];
	t_float	normals[3];
	t_float	diameter;
	t_float	height;
	t_float	colors[3];

	if (!str_to_vec3(args[1], points) || !check_range(points, RANGE_FLOAT, 3))
		return (FALSE);
	if (!str_to_vec3(args[2], normals) || \
		!check_range(normals, RANGE_NORMAL, 3))
		return (FALSE);
	if (!str_to_float(args[3], &diameter) || \
		!check_range(&diameter, RANGE_LENGTH, 1))
		return (FALSE);
	if (!str_to_float(args[4], &height) || \
		!check_range(&height, RANGE_LENGTH, 1))
		return (FALSE);
	if (!str_to_vec3(args[5], colors) || \
		!check_range(colors, RANGE_COLOR, 3))
		return (FALSE);
	if (!modify_cylinder_args(\
		&(t_cylinder_tmp_content){points, normals, diameter, height, colors}, \
			data))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_cylinder(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (arg_num != CYLINDER_ARG_NUM)
		return (FALSE);
	if (!set_cylinder(args, data))
		return (FALSE);
	return (TRUE);
}
