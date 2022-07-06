#ifndef RAY_H
# define RAY_H

#include "minirt.h"

typedef struct s_ray
{
	t_vec3 point;
	t_vec3 direction;
}t_ray;

t_vec3	ray_at(t_ray ray, float t);

#endif