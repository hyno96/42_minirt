/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:02:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 18:03:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "objects_f.h"
#include "ray.h"
#include "render.h"

static t_float	hit_cone_cap(t_cone *cn, t_ray r)
{
	t_float	dist_cap1;
	t_vec3	temp_rayat;
	t_vec3	h;

	h = vec3_plus(cn->origin, vec3_mult_scalar(cn->normal, cn->height));
	dist_cap1 = hit_plane(h, cn->normal, r);
	temp_rayat = ray_at(r, dist_cap1);
	if (vec3_square_len(vec3_minus(h, temp_rayat)) \
		> cn->radius * cn->radius)
		dist_cap1 = -1;
	return (dist_cap1);
}

// void	set_hit_record_cn(t_cone *cn, t_hit_record *rec)
// {
// 	t_vec3	new_origin;
// 	t_vec3	new_nomal;
// 	t_vec3	ph;
// 	t_float	hh;
// 	t_vec3	h;

// 	new_origin = vec3_plus(cn->origin, \
// 		vec3_mult_scalar(cn->normal, cn->height));
// 	new_nomal = vec3_mult_scalar(cn->normal, -1);
// 	if (vec3_dot(vec3_minus(rec->hit_point, new_origin), \
// 		new_nomal) <= 0.001)
// 		rec->normal_unit = cn->normal;
// 	else
// 	{
// 		ph = vec3_minus(rec->hit_point, cn->origin);
// 		hh = vec3_len(ph) / (vec3_dot(ph, cn->normal) / vec3_len(ph));
// 		h = vec3_plus(cn->origin, vec3_mult_scalar(cn->normal, hh));
// 		rec->normal_unit = vec3_unit(vec3_minus(rec->hit_point, h));
// 	}
// 	rec->surf = conv_cn(rec->obj)->surf;
// }

void	set_hit_record_cn(t_cone *cn, t_hit_record *rec)
{
	t_vec3	new_origin;
	t_vec3	new_nomal;
	t_vec3	ph;
	t_float	hh;
	t_vec3	h;

	new_origin = vec3_plus(cn->origin, \
		vec3_mult_scalar(cn->normal, cn->height));
	new_nomal = vec3_mult_scalar(cn->normal, -1);
	if (vec3_dot(vec3_minus(rec->hit_point, new_origin), \
		new_nomal) <= 0.001)
	{
		rec->normal_unit = cn->normal;
		rec->perpen = 0;
	}
	else
	{
		ph = vec3_minus(rec->hit_point, cn->origin);
		hh = vec3_len(ph) / (vec3_dot(ph, cn->normal) / vec3_len(ph));
		h = vec3_plus(cn->origin, vec3_mult_scalar(cn->normal, hh));
		rec->normal_unit = vec3_unit(vec3_minus(rec->hit_point, h));
		rec->perpen = vec3_dot(ph, cn->normal);
	}
	rec->perpen_at = ray_at(ray(cn->origin, cn->normal), rec->perpen);
	rec->surf = conv_cn(rec->obj)->surf;
}

static t_quadratic_eq	get_cone_quadratic_eq(t_cone *cn, t_ray *ray)
{
	t_vec3			h;
	t_vec3			w;
	t_float			m;
	t_quadratic_eq	eq;

	h = vec3_mult_scalar(cn->normal, cn->height);
	w = vec3_minus(ray->point, cn->origin);
	m = (cn->radius * cn->radius) / (cn->height * cn->height);
	eq.a = vec3_dot(ray->direction, ray->direction) \
		- (m + 1) * vec3_dot(ray->direction, cn->normal) \
		* vec3_dot(ray->direction, cn->normal);
	eq.hb = vec3_dot(ray->direction, w) \
		- (m + 1) * vec3_dot(ray->direction, cn->normal) \
		* vec3_dot(w, cn->normal);
	eq.c = vec3_dot(w, w) \
		- (m + 1) * vec3_dot(w, cn->normal) * vec3_dot(w, cn->normal);
	eq.d = eq.hb * eq.hb - eq.a * eq.c;
	return (eq);
}

static t_float	hit_cone_body(t_cone *cn, t_ray ray, t_quadratic_eq *eq)
{
	t_vec3	h;
	t_vec3	line;
	t_float	intersection;
	t_float	sol1;
	t_float	sol2;

	h = vec3_mult_scalar(cn->normal, cn->height);
	sol1 = (-eq->hb - sqrt(eq->d)) / eq->a;
	line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, sol1));
	intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
	if (!(0 <= intersection && intersection <= vec3_len(h)))
		sol1 = 0;
	sol2 = (-eq->hb + sqrt(eq->d)) / eq->a;
	line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, sol2));
	intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
	if (!(0 <= intersection && intersection <= vec3_len(h)))
		sol2 = 0;
	return (find_small_solution(sol1, sol2));
}

t_float	hit_cone(t_cone *cn, t_ray ray)
{
	t_quadratic_eq	eq;
	t_float			dist_cap;
	t_float			dist_body;

	eq = get_cone_quadratic_eq(cn, &ray);
	if (eq.d < 0)
		return (-1);
	dist_cap = hit_cone_cap(cn, ray);
	dist_body = hit_cone_body(cn, ray, &eq);
	return (find_small_solution(dist_cap, dist_body));
}
