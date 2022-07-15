/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:25:48 by hyno              #+#    #+#             */
/*   Updated: 2022/07/13 20:11:44 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "render.h"
#include "ray.h"
#include "structure.h"
#include "mapping_f.h"
#include "checkerboard_f.h"

t_color3	get_color_phong(t_ray ray, t_data data)
{
	t_hit_record	record;
	t_vec3			specular_direction;
	t_point3		rtn_color;

	ray.direction = vec3_unit(ray.direction);
	if (complict(ray, data, &record) == TRUE)
	{
		// if (record.normal_unit.x < 0)
		// 	record.normal_unit.x *= -1;
		// if (record.normal_unit.y < 0)
		// 	record.normal_unit.y *= -1;
		// if (record.normal_unit.z < 0)
		// 	record.normal_unit.z *= -1;
		// return (vec3_mult_scalar(record.normal_unit, 100));
		
		if (vec3_dot(record.normal_unit, ray.direction) > 0)
			record.normal_unit = vec3_mult_scalar(record.normal_unit, -1);
		
		specular_direction = vec3_minus(ray.direction, vec3_mult_scalar(\
			record.normal_unit, \
			2.0 * vec3_dot(ray.direction, record.normal_unit)));
		rtn_color = trace_dot_light(\
			record.hit_point, specular_direction, record.normal_unit, data);
		if (data.setting->use_ambient)
			rtn_color = vec3_plus(rtn_color, \
				vec3_mult_scalar(data.ambient, data.setting->ambient_ratio));
		if (record.surf.use_ctc == 1)
			rtn_color = vec3_mult(rtn_color, vec3_div(get_color_in_texture(record), 255));
		else if (record.surf.use_ctc == 2)
			rtn_color = vec3_mult(rtn_color, vec3_div(get_color_checker(record), 255));
		else
			rtn_color = vec3_mult(rtn_color, vec3_div(record.surf.color, 255));
		return (rtn_color);
	}
	return (vec3(100, 0, 0));
}
