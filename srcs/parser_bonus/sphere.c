/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:11:19 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/19 14:46:16 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "parser_bonus.h"
#include "libft.h"

static t_bool	modify_sphere_args(t_sphere_tmp_content *sp_content, \
									t_data *data, char **args, size_t arg_num)
{
	t_sphere	*sp;
	t_list		*list;
	t_bool		result;

	result = TRUE;
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (FALSE);
	sp->origin = vec3(sp_content->points[0], sp_content->points[1], \
						sp_content->points[2]);
	sp->radius = (t_float)(sp_content->diameter / 2.0);
	sp->surf.color = vec3(sp_content->colors[0], sp_content->colors[1], \
							sp_content->colors[2]);
	sp->surf.use_ctc = CTC_COLOR;
	if (arg_num >= BONUS_SPHERE_ARG_NUM && \
		!set_bonus_surf(args, &(sp->surf), data, BONUS_SPHERE_ARG_NUM))
		result = FALSE;
	else
	{
		list = ft_lstnew((void *)sp);
		list->type = SP;
		ft_lstadd_back(&(data->object_list), list);
	}
	return (result);
}

static t_bool	set_sphere(char **args, t_data *data, size_t arg_num)
{
	t_float	points[3];
	t_float	diameter;
	t_float	colors[3];

	if (!str_to_vec3(args[1], points) || !check_range(points, RANGE_FLOAT, 3))
		return (FALSE);
	if (!str_to_float(args[2], &diameter) || \
		!check_range(&diameter, RANGE_LENGTH, 1))
		return (FALSE);
	if (!str_to_vec3(args[3], colors) || !check_range(colors, RANGE_COLOR, 3))
		return (FALSE);
	if (!modify_sphere_args(\
			&(t_sphere_tmp_content){points, diameter, colors}, data, \
			args, arg_num))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_sphere(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (arg_num != SPHERE_ARG_NUM && arg_num != BONUS_SPHERE_ARG_NUM)
		return (FALSE);
	if (!set_sphere(args, data, arg_num))
		return (FALSE);
	return (TRUE);
}
