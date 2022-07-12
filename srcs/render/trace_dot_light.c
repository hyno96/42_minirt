/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:45:15 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 16:49:32 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "structure.h"
#include "objects.h"
#include "ray.h"
#include "libft.h"
#include <math.h>

static t_color3	get_specular_color( \
	t_vec3 direction_to_light, t_vec3 specular_unit, t_list *head, t_data data)
{
	t_vec3		direction_to_light;
	t_color3	rtn_color;
	t_float		cos_theta;

	rtn_color = vec3(0, 0, 0);
	if (data.setting->use_dot_light_specular == FALSE)
		return (rtn_color);
	cos_theta = vec3_dot(specular_unit, direction_to_light) / \
		(vec3_len(direction_to_light));
	cos_theta = cos_theta * cos_theta * cos_theta * cos_theta * cos_theta;
	rtn_color = vec3_plus(rtn_color, \
		vec3_mult_scalar(conv_li(head)->color, cos_theta));
	rtn_color = vec3_mult_scalar(rtn_color, \
		data.setting->dot_light_specular_ratio);
	return (rtn_color);
}

static t_color3	get_diffuse_color( \
	t_vec3 direction_to_light, t_vec3 normal_unit, t_list *head, t_data data)
{
	t_color3	rtn_color;
	t_float		cos_theta;

	rtn_color = vec3(0, 0, 0);
	if (data.setting->use_dot_light_diffuse == FALSE)
		return (rtn_color);
	cos_theta = vec3_dot(normal_unit, direction_to_light) / \
		(vec3_len(direction_to_light));
	rtn_color = vec3_plus(rtn_color, \
		vec3_mult_scalar(conv_li(head)->color, cos_theta));
	rtn_color = vec3_mult_scalar(rtn_color, \
		data.setting->dot_light_diffuse_ratio);
	return (rtn_color);
}

// dev_comment_hyno
t_color3	trace_dot_light( \
	t_point3	shoot_coord, t_vec3 specular, t_vec3 normal_unit, t_data data)
{
	t_list			*head;
	t_ray			ray;
	t_hit_record	record;
	t_color3		rtn_color;
	t_float			dist;

	rtn_color = vec3(0, 0, 0);
	head = data.dot_lights;
	while (head)
	{
		ray.point = shoot_coord;
		ray.direction = vec3_minus(conv_li(head)->origin, shoot_coord);
		dist = vec3_square_len(ray.direction);
		if (complict(ray, data, &record) < 0 || \
			record.dist * record.dist > dist)
		{
			dist = sqrt(dist);
			rtn_color = vec3_div(vec3_plus(rtn_color, get_specular_color \
				(shoot_coord, specular, head, data)), dist);
			rtn_color = vec3_div(vec3_plus(rtn_color, get_diffuse_color \
				(shoot_coord, normal_unit, head, data)), dist);
		}
		head = head->next;
	}
	return (rtn_color);
}
