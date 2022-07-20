/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:55:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 12:16:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser_bonus.h"
#include "libft.h"

static t_bool	modify_cylinder_args(t_cylinder_tmp_content *cy_content, \
										t_data *data, char **args, size_t arg_num)
{
	t_cylinder	*cy;
	t_list		*list;
	t_bool		result;

	result = TRUE;
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (FALSE);
	cy->origin = vec3(cy_content->points[0], cy_content->points[1], \
						cy_content->points[2]);
	cy->normal = vec3_unit(vec3(cy_content->normals[0], \
						cy_content->normals[1],	cy_content->normals[2]));
	cy->radius = (t_float)(cy_content->diameter / 2.0);
	cy->height = cy_content->height;
	cy->surf.color = vec3(cy_content->colors[0], cy_content->colors[1], \
							cy_content->colors[2]);
	cy->surf.use_ctc = CTC_COLOR;
	if (arg_num > CYLINDER_ARG_NUM && \
		!tmp_set_bonus_surf(args, &(cy->surf), data, CYLINDER_ARG_NUM))
		result = FALSE;
	else
	{
		list = ft_lstnew((void *)cy);
		list->type = CY;
		ft_lstadd_back(&(data->object_list), list);
	}
	return (TRUE);
}

static t_bool	set_cylinder(char **args, t_data *data, size_t arg_num)
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
			data, args, arg_num))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_cylinder(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (!(CYLINDER_ARG_NUM <= arg_num && arg_num <= BONUS_CYLINDER_ARG_NUM))
		return (FALSE);
	if (!set_cylinder(args, data, arg_num))
		return (FALSE);
	return (TRUE);
}
