/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:02:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:03:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"
#include "libft.h"

static t_bool	modify_sphere_args(t_float points[3], t_float diameter, \
									t_float colors[3], t_data *data)
{
	t_sphere	*sp;
	t_list		*list;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (FALSE);
	sp->origin = vec3(points[0], points[1], points[2]);
	sp->radius = (t_float)(diameter / 2.0);
	sp->surf.color = vec3(colors[0], colors[1], colors[2]);
	list = ft_lstnew((void *)sp);
	list->type = SP;
	ft_lstadd_back(&(data->object_list), list);
	return (TRUE);
}

static t_bool	set_sphere(char **args, t_data *data)
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
	if (!modify_sphere_args(points, diameter, colors, data))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_sphere(char **args, t_data *data)
{
	size_t	arg_num;

	arg_num = get_arg_num(args);
	if (arg_num != SPHERE_ARG_NUM)
		return (FALSE);
	if (!set_sphere(args, data))
		return (FALSE);
	return (TRUE);
}
