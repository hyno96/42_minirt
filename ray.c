#include "ray.h"

t_vec3	ray_at(t_ray ray, float t)
{
	// t_vec3 a;
	// t_vec3 b;

	// a = ray.direction;
	// b = ray.point;
	// ft_vec3_multi_float(&b, t, &b);
	// ft_vec3_add(&a, &a, &b);
	// return (a);
	return (vec3_plus(ray.point, vec3_mult_scalar(ray.direction, t)));
}
