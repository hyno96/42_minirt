/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:59:35 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:51:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser_bonus.h"
#include "libft.h"

static t_bool	modify_plane_args(t_plane_tmp_content *pl_content, \
									t_data *data, char **args, size_t arg_num)
{
	t_plane	*pl;
	t_list	*list;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (FALSE);
	pl->origin = vec3(pl_content->points[0], pl_content->points[1], \
					pl_content->points[2]);
	pl->normal = vec3_unit(vec3(pl_content->normals[0], \
					pl_content->normals[1], pl_content->normals[2]));
	pl->surf.color = vec3(pl_content->colors[0], \
						pl_content->colors[1], pl_content->colors[2]);
	pl->surf.use_ctc = CTC_COLOR;
	if (arg_num > PLANE_ARG_NUM \
		&& !set_bonus_surf(args, &(pl->surf), data, PLANE_ARG_NUM))
	{
		free(pl);
		return (FALSE);
	}
	list = ft_lstnew((void *)pl);
	list->type = PL;
	ft_lstadd_back(&(data->object_list), list);
	return (TRUE);
}

static t_bool	set_plane(char **args, t_data *data, size_t arg_num)
{
	t_float	points[3];
	t_float	normals[3];
	t_float	colors[3];

	if (!str_to_vec3(args[1], points) || !check_range(points, RANGE_FLOAT, 3))
		return (FALSE);
	if (!str_to_vec3(args[2], normals) || \
		!check_range(normals, RANGE_NORMAL, 3))
		return (FALSE);
	if (!str_to_vec3(args[3], colors) || !check_range(colors, RANGE_COLOR, 3))
		return (FALSE);
	if (!modify_plane_args(\
			&(t_plane_tmp_content){points, normals, colors}, data, \
			args, arg_num))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_plane(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (!(PLANE_ARG_NUM <= arg_num && arg_num <= BONUS_PLANE_ARG_NUM))
		return (FALSE);
	if (!set_plane(args, data, arg_num))
		return (FALSE);
	return (TRUE);
}
