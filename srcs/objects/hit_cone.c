#include "objects_f.h"
#include "ray.h"
#include <math.h>

static t_float	hit_cone_cap(t_cone *cn, t_ray r)
{
	t_float	dist_cap1;
	t_float	dist_cap2;
	t_vec3	temp_rayat;
	t_float	ignore;
	t_vec3	origin2;
	t_vec3	h;

	ignore = 0.001;
	h = vec3_plus(cn->origin, vec3_mult_scalar(cn->normal, cn->height));
	dist_cap1 = hit_plane(vec3_plus(h, cn->origin), cn->normal, r);
	temp_rayat = ray_at(r, dist_cap1);
	if (vec3_square_len(vec3_minus(cn->origin, temp_rayat)) \
		> cn->radius * cn->radius)
		dist_cap1 = -1;
	return (dist_cap1);
}


#include <stdio.h>
t_float	hit_cone(t_cone *cn, t_ray ray)
{
	t_vec3	h;
	t_vec3	w;
	t_float	m;
	t_float	a;
	t_float	hb;
	t_float	c;
	t_float	d;
	t_float	root;
	t_float	cosin_theta;
	t_vec3	line;
	t_float	intersection;
	t_float	sol1;
	t_float	sol2;

	h = vec3_mult_scalar(cn->normal, cn->height);
	w = vec3_minus(ray.point, cn->origin);
	m = (cn->radius * cn->radius) / (cn->height * cn->height);
	a = vec3_dot(ray.direction, ray.direction) \
		- (m + 1) * vec3_dot(ray.direction, cn->normal) \
		* vec3_dot(ray.direction, cn->normal);
	hb = vec3_dot(ray.direction, w) \
		- (m + 1) * vec3_dot(ray.direction, cn->normal) \
		* vec3_dot(w, cn->normal);
	c = vec3_dot(w, w) \
		- (m + 1) * vec3_dot(w, cn->normal) * vec3_dot(w, cn->normal);
	d = hb * hb - a * c;
	if (d < 0)
		return (-1);
	// else if (d == 0)
	// {
	// 	cosin_theta = vec3_len(h) / (sqrt(vec3_square_len(h) + cn->radius * cn->radius));
	// 	if (cosin_theta != fabs(vec3_dot(ray.direction, cn->normal)))
	// 	{
	// 		root = -hb / a;
	// 		line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, root));
	// 		intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
	// 		if (0 <= intersection && intersection <= vec3_len(h))
	// 			return (root);
	// 		if (intersection > vec3_len(h))
	// 			return (hit_cone_cap(cn, ray));
	// 	}
	// }
	else if (d >= 0)
	{
		sol1 = (-hb - sqrt(d)) / a;
		line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, sol1));
		intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
		if (!(0 <= intersection && intersection <= vec3_len(h)))
			sol1 = 0;
		// if (intersection > vec3_len(h))
		// 	return (hit_cone_cap(cn, ray));
		sol2 = (-hb + sqrt(d)) / a;
		line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, sol2));
		intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
		if (!(0 <= intersection && intersection <= vec3_len(h)))
			sol2 = 0;
		// if (intersection > vec3_len(h))
		// 	return (hit_cone_cap(cn, ray));
		return (find_small_solution(sol1, sol2));
	}
	return (-1);	
}