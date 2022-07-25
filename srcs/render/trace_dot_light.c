/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:26:15 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:26:16 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "structure.h"
#include "objects_f.h"
#include "ray.h"
#include "libft.h"
#include <math.h>
#include "render.h"

static t_color3	get_specular_color( \
	t_vec3 direction_to_light, t_vec3 specular_unit, t_list *head, t_data data)
{
	t_color3	rtn_color;
	t_float		cos_theta;

	rtn_color = vec3(0, 0, 0);
	if (data.setting->use_dot_light_specular == FALSE)
		return (rtn_color);
	if (vec3_dot(specular_unit, direction_to_light) < 0)
		return (rtn_color);
	cos_theta = vec3_dot(specular_unit, direction_to_light) / \
		(vec3_len(direction_to_light));
	cos_theta = cos_theta * cos_theta * cos_theta * cos_theta;
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
	if (cos_theta < 0)
		cos_theta *= -1;
	rtn_color = vec3_plus(rtn_color, \
		vec3_mult_scalar(conv_li(head)->color, cos_theta));
	rtn_color = vec3_mult_scalar(rtn_color, \
		data.setting->dot_light_diffuse_ratio);
	return (rtn_color);
}

static t_color3	trace_dot_light_inside( \
	t_list *head, t_vec3 arg[3], t_data data)
{
	t_ray			myray;
	t_float			dist;
	t_hit_record	record;
	t_color3		rtn_color;

	myray = ray(arg[0], vec3_minus(conv_li(head)->origin, arg[0]));
	dist = vec3_len(myray.direction);
	myray.direction = vec3_unit(myray.direction);
	ft_memset((void *)(&rtn_color), 0, sizeof(t_color3));
	if (complict(myray, data, &record) == FALSE || record.dist > dist)
	{
		rtn_color = vec3_plus(\
			get_diffuse_color(myray.direction, arg[2], head, data), \
			get_specular_color(myray.direction, arg[1], head, data));
		if (data.setting->use_dist_lose != 0)
			rtn_color = vec3_div(rtn_color, dist);
	}
	return (rtn_color);
}

t_color3	trace_dot_light( \
	t_point3	origin, t_vec3 specular, t_vec3 normal_unit, t_data data)
{
	t_list			*head;
	t_color3		rtn_color;
	t_vec3			arg[3];

	rtn_color = vec3(0, 0, 0);
	head = data.dot_lights;
	while (head)
	{
		arg[0] = origin;
		arg[1] = specular;
		arg[2] = normal_unit;
		rtn_color = vec3_plus(rtn_color, \
			trace_dot_light_inside(head, arg, data));
		head = head->next;
	}
	return (rtn_color);
}
