/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:25:48 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 15:52:14 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "render.h"
#include "ray.h"
#include "structure.h"

t_color3	get_color_phong(t_ray ray, t_data data)
{
	t_hit_record	record;
	t_vec3			specular_direction;
	t_point3		rtn_color;

	if (complict(ray, data, &record) == TRUE)
	{
		specular_direction = vec3_minus(ray.direction, vec3_mult_scalar(\
			record.normal_unit, \
			2 * vec3_dot(ray.direction, record.normal_unit)));
		rtn_color = trace_dot_light(\
			record.hit_point, specular_direction, record.normal_unit, data);
		if (data.setting->use_ambient)
			rtn_color = vec3_plus(rtn_color, \
				vec3_mult_scalar(data.ambient, data.setting->ambient_ratio));
		return (rtn_color);
	}
	return (vec3(0, 0, 0));
}
