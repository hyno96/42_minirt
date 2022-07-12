#include "objects.h"
#include "ray.h"

// dev_comment
// ray의 direction이 유닛벡터가 아니여도 정상적으로 작동합니까?
t_float	hit_sphere(t_point3 center, t_float radius, t_ray r) {
    t_vec3	oc;
	t_float	cal[4];
	t_float	sol[2];

	oc = vec3(r.point.x - center.x ,r.point.y - center.y ,r.point.z - center.z);
    cal[0] = ft_vec3_dot(&(r.direction), &(r.direction));
    cal[1] = 2.0 * ft_vec3_dot(&oc, &(r.direction));
    cal[2] = ft_vec3_dot(&oc, &oc) - radius * radius;
    cal[3] = cal[1] * cal[1] - 4 * cal[0] * cal[2];
	if (cal[3] < 0)
		return (-1);
	sol[0] = (-cal[1] + (t_float)sqrt(cal[3]))/ (2 * cal[0]);
	sol[1] = (-cal[1] - (t_float)sqrt(cal[3]))/ (2 * cal[0]);
	if (sol[0] < 0 && sol[1] < 0)
		return (-1);
	if (sol[1] < 0)
		return (sol[0]);
	return (sol[1]);
}

t_float	hit_plane(t_point3 coord, t_vec3 normal_vec, t_ray ray)
{
	t_float vn;
	t_float sol;
	t_vec3 normal_vec;

	if (vec3_dot(normal_vec, ray.direction) < 0)
		normal_vec = vec3_mult_scalar(normal_vec, -1);
	vn = abs_float(vec3_dot(normal_vec, ray.direction));
	if (vn <= 0)
		return (-1);
	sol = vec3_dot(vec3_div(vec3_minus(coord, ray.point), vn), normal_vec);
	return (sol);
}