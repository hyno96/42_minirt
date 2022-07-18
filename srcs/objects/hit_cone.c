#include "objects_f.h"
#include "ray.h"
#include <math.h>


#include <stdio.h>
t_float	hit_cone(t_cone *cn, t_ray ray)
{
	t_float	a;
	t_float	h_b;
	t_float	c;
	t_float	d;
	t_float	cosin_theta_squared;
	t_float	root;

	cosin_theta_squared = (cn->height * cn->height) / ((cn->height * cn->height) + (cn->radius * cn->radius));
	a = vec3_dot(ray.direction, cn->normal) * vec3_dot(ray.direction, cn->normal) - cosin_theta_squared;
	h_b = vec3_dot(ray.direction, cn->normal) * (vec3_dot(vec3_minus(cn->origin, ray.point), cn->normal)) - \
			vec3_dot(vec3_minus(cn->origin, ray.point), ray.direction) * cosin_theta_squared;
	c = vec3_dot(vec3_minus(cn->origin, ray.point), cn->normal) * vec3_dot(vec3_minus(cn->origin, ray.point), cn->normal) - \
		vec3_dot(vec3_minus(cn->origin, ray.point), vec3_minus(cn->origin, ray.point)) * cosin_theta_squared;
	d = h_b * h_b - a * c;
	if (d < 0)
		return (-1);
	root = (-h_b - (h_b * h_b - a * c)) / a;
	if (vec3_dot(vec3_plus(vec3_minus(ray.point, cn->origin), vec3_mult_scalar(ray.direction, root)), cn->normal) > 0)
		return (root);
	return (-1);
}