/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:57:48 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:07:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser_bonus.h"
#include "libft.h"

static t_bool	modify_dot_light_args(t_float points[3], t_float ratio, \
									t_float colors[3], t_data *data)
{
	t_dot_light	*light;
	t_list		*list;

	light = (t_dot_light *)malloc(sizeof(t_dot_light));
	if (!light)
		return (FALSE);
	light->origin = vec3(points[0], points[1], points[2]);
	light->color = vec3_mult_scalar(\
		vec3(colors[0], colors[1], colors[2]), ratio);
	list = ft_lstnew((void *)light);
	list->type = DOT_LI;
	ft_lstadd_back(&(data->dot_lights), list);
	return (TRUE);
}

static t_bool	set_dot_light(char **args, t_data *data)
{
	t_float	points[3];
	t_float	ratio;
	t_float	colors[3];

	if (!str_to_vec3(args[1], points) || !check_range(points, RANGE_FLOAT, 3))
		return (FALSE);
	if (!str_to_float(args[2], &ratio) || !check_range(&ratio, RANGE_RATIO, 1))
		return (FALSE);
	if (!str_to_vec3(args[3], colors) || !check_range(colors, RANGE_COLOR, 3))
		return (FALSE);
	if (!modify_dot_light_args(points, ratio, colors, data))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_dot_light(t_line_info *line_info, char **args, t_data *data)
{
	size_t	arg_num;

	line_info->check_dup |= DUP_CHECK_LIGHT;
	arg_num = get_arg_num(args);
	if (arg_num != LIGHT_ARG_NUM)
		return (FALSE);
	if (!set_dot_light(args, data))
		return (FALSE);
	return (TRUE);
}
