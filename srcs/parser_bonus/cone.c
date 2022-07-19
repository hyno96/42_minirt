/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:55:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/19 14:45:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser_bonus.h"
#include "libft.h"


static t_bool	modify_cone_args(t_cone_tmp_content *cn_content, \
										t_data *data)
{
	t_cone	*cn;
	t_list	*list;

	cn = (t_cone *)malloc(sizeof(t_cone));
	if (!cn)
		return (FALSE);
	cn->origin = vec3(cn_content->points[0], cn_content->points[1], \
						cn_content->points[2]);
	cn->normal = vec3(cn_content->normals[0], cn_content->normals[1], \
						cn_content->normals[2]);
	// if (!check_normal(cn->normal))
	// {
	// 	free(cn);
	// 	return (FALSE);
	// }
	cn->normal = vec3_unit(cn->normal);
	cn->radius = (t_float)(cn_content->diameter / 2.0);
	cn->height = cn_content->height;
	cn->surf.color = vec3(cn_content->colors[0], cn_content->colors[1], \
							cn_content->colors[2]);
	cn->surf.use_ctc = CTC_COLOR;
	list = ft_lstnew((void *)cn);
	list->type = CN;
	ft_lstadd_back(&(data->object_list), list);
	return (TRUE);
}

static t_bool	set_cone(char **args, t_data *data)
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
	if (!modify_cone_args(\
		&(t_cone_tmp_content){points, normals, diameter, height, colors}, \
			data))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_cone(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (arg_num != CONE_ARG_NUM)
		return (FALSE);
	if (!set_cone(args, data))
		return (FALSE);
	return (TRUE);
}
