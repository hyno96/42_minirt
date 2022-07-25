/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:17:16 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:17:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_f.h"
#include "ray.h"
#include <math.h>

t_float	hit_sphere(t_point3 center, t_float radius, t_ray r)
{
	t_vec3	oc;
	t_float	cal[3];

	oc = vec3(r.point.x - center.x, r.point.y - center.y, r.point.z - center.z);
	cal[0] = vec3_dot((r.direction), (r.direction));
	cal[1] = 2.0 * vec3_dot(oc, (r.direction));
	cal[2] = vec3_dot(oc, oc) - radius * radius;
	return (find_quadratic_formula(cal[0], cal[1], cal[2]));
}

t_float	hit_plane(t_point3 coord, t_vec3 normal_vec, t_ray ray)
{
	t_float	dot_n_pa;
	t_float	dot_n_rd;
	t_float	sol;
	t_float	ignore;

	ignore = 0.001;
	if (vec3_dot(normal_vec, ray.direction) > 0)
		normal_vec = vec3_mult_scalar(normal_vec, -1);
	dot_n_pa = vec3_dot(normal_vec, vec3_minus(coord, ray.point));
	dot_n_rd = vec3_dot(normal_vec, ray.direction);
	sol = dot_n_pa / dot_n_rd;
	if (sol > ignore)
		return (sol);
	return (-1);
}
