/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:52:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 10:16:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "parser.h"
#include "mlx_window.h"
#include "vec3.h"

static t_vec3	get_horizontal(t_camera *cam)
{
	t_vec3	vec_y;
	t_vec3	vec_z;

	vec_y = vec3(0.0, 1.0, 0.0);
	vec_z = vec3(0.0, 0.0, -1.0);
	if (vec3_len(vec3_cross(vec_y, cam->direction)))
		return (vec3_unit(vec3_cross(cam->direction, vec_y)));
	else
		return (vec3_unit(vec3_cross(cam->direction, vec_z)));
}

static t_point3	get_left_bottom(t_camera *cam)
{
	t_point3	temp;

	temp = vec3_plus(cam->origin, \
						vec3_mult_scalar(cam->direction, cam->focal_len));
	temp = vec3_plus(temp, \
						vec3_mult_scalar(cam->horizontal, \
						-(t_float)(WIDTH - 1) / 2));
	temp = vec3_plus(temp, \
						vec3_mult_scalar(cam->vertical, \
						-(t_float)(HEIGHT - 1) / 2));
	return (temp);
}

static t_bool	modify_camera_args(t_float points[3], t_float normals[3], \
								t_float fov, t_data *data)
{
	t_camera	*cam;

	cam = &(data->camera);
	cam->origin = vec3(points[0], points[1], points[2]);
	cam->direction = vec3_unit(vec3(normals[0], normals[1], normals[2]));
	cam->horizontal = get_horizontal(cam);
	cam->vertical = vec3_unit(vec3_cross(cam->horizontal, cam->direction));
	cam->focal_len = (t_float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);
	cam->left_bottom = get_left_bottom(cam);
	return (TRUE);
}

static t_bool	set_camera(char **args, t_data *data)
{
	t_float	points[3];
	t_float	normals[3];
	t_float	fov;

	if (!str_to_vec3(args[1], points) || \
		!check_range(points, RANGE_FLOAT, 3))
		return (FALSE);
	if (!str_to_vec3(args[2], normals) || \
		!check_range(normals, RANGE_NORMAL, 3))
		return (FALSE);
	if (!str_to_float(args[3], &fov) || !check_range(&fov, RANGE_FOV, 1))
		return (FALSE);
	if (!modify_camera_args(points, normals, fov, data))
		return (FALSE);
	return (TRUE);
}

t_bool	parse_camera(t_line_info *line_info, char **args, t_data *data)
{
	size_t	arg_num;

	if (line_info->check_dup & DUP_CHECK_CAMERA)
		return (FALSE);
	line_info->check_dup |= DUP_CHECK_CAMERA;
	arg_num = get_arg_num(args);
	if (arg_num != CAMERA_ARG_NUM)
		return (FALSE);
	if (!set_camera(args, data))
		return (FALSE);
	return (TRUE);
}
