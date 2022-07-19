#include "objects_f.h"
#include "ray.h"
#include <math.h>


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
	else if (d == 0)
	{
		cosin_theta = vec3_len(h) / (sqrt(vec3_square_len(h) + cn->radius * cn->radius));
		if (cosin_theta != fabs(vec3_dot(ray.direction, cn->normal)))
		{
			root = -hb / a;
			line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, root));
			intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
			if (0 <= intersection && intersection <= vec3_len(h))
				return (root);
		}
	}
	else if (d > 0)
	{
		root = (-hb - sqrt(d)) / a;
		line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, root));
		intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
		if (0 <= intersection && intersection <= vec3_len(h))
			return (root);
		root = (-hb + sqrt(d)) / a;
		line = vec3_plus(ray.point, vec3_mult_scalar(ray.direction, root));
		intersection = vec3_dot(vec3_minus(line, cn->origin), cn->normal);
		if (0 <= intersection && intersection <= vec3_len(h))
			return (root);
	}
	return (-1);	
}