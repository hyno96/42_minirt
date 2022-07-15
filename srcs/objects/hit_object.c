#include "objects_f.h"
#include "ray.h"
#include <math.h>

// dev_comment
// ray의 direction이 유닛벡터가 아니여도 정상적으로 작동합니까?
t_float	hit_sphere(t_point3 center, t_float radius, t_ray r)
{
	t_vec3	oc;
	t_float	cal[4];
	t_float	sol[2];

	oc = vec3(r.point.x - center.x ,r.point.y - center.y ,r.point.z - center.z);
	cal[0] = vec3_dot((r.direction), (r.direction));
    cal[1] = 2.0 * vec3_dot(oc, (r.direction));
    cal[2] = vec3_dot(oc, oc) - radius * radius;
    cal[3] = cal[1] * cal[1] - 4.0 * cal[0] * cal[2];
	if (cal[3] < 0)
		return (-1);
	sol[0] = (-cal[1] + (t_float)sqrt(cal[3]))/ (2 * cal[0]);
	sol[1] = (-cal[1] - (t_float)sqrt(cal[3]))/ (2 * cal[0]);
	if (sol[0] < 0.001 && sol[1] < 0.001)
		return (-1);
	if (sol[1] < 0.001 && sol[0] > 0.001)
		return (sol[0]);
	if (sol[1] > 0.001)
		return (sol[1]);
	return (-1);
}

t_float	hit_plane(t_point3 coord, t_vec3 normal_vec, t_ray ray)
{
	t_float dot_n_pa;
	t_float	dot_n_rd;
	t_float sol;

	if (vec3_dot(normal_vec, ray.direction) > 0)
		normal_vec = vec3_mult_scalar(normal_vec, -1);
	dot_n_pa = vec3_dot(normal_vec, vec3_minus(coord, ray.point));
	dot_n_rd = vec3_dot(normal_vec, ray.direction);
	// if (dot_n_pa < 0)
	// 	return (-1);
	sol = dot_n_pa / dot_n_rd;
	if (sol > 0.001)
		return (sol);
	return (-1);
}

t_float	hit_cylinder_cap(t_cylinder cylinder, t_ray myray)
{
	t_float	dist_cap1;
	t_float dist_cap2;
	t_vec3	temp_rayat;
	t_float	ignore;
	t_vec3	origin2;

	cylinder.normal = vec3_unit(cylinder.normal);
	ignore = 0.001;
	dist_cap1 = hit_plane(cylinder.origin, cylinder.normal, myray);
	temp_rayat = ray_at(myray, dist_cap1);
	if (vec3_square_len(vec3_minus(cylinder.origin, temp_rayat)) \
		> cylinder.radius * cylinder.radius)
		dist_cap1 = -1;
	origin2 = ray_at(ray(cylinder.origin, cylinder.normal), cylinder.height);
	dist_cap2 = hit_plane(origin2, cylinder.normal, myray);
	temp_rayat = ray_at(myray, dist_cap2);
	if (vec3_square_len(vec3_minus(origin2, temp_rayat)) \
		> cylinder.radius * cylinder.radius)
		dist_cap2 = -1;
	if (dist_cap1 > ignore && (dist_cap2 < ignore || dist_cap1 < dist_cap2))
		return (dist_cap1);
	else if (dist_cap2 > ignore && (dist_cap1 < ignore || dist_cap2 < dist_cap1))
		return (dist_cap2);
	return (-1);
}

t_float	hit_cylinder_body(t_cylinder cylinder, t_ray ray)
{
	t_float	a;
	t_float	b;
	t_float	c;
	t_vec3 	tempvec;
	t_vec3	tempvec2;

	t_float temp1;
	t_float temp2;

	tempvec = vec3_cross(cylinder.normal, ray.direction);
	a = vec3_dot(tempvec, tempvec);
	tempvec2 = vec3_cross(cylinder.origin, cylinder.normal);
	b = vec3_dot(tempvec, tempvec2) * 2.0;
	c = vec3_dot(tempvec2, tempvec2) - cylinder.radius * cylinder.radius;
	// temp1 = vec3_dot(cylinder.normal, ray.direction);
	// a = temp1 * temp1;
	// temp2= vec3_dot(cylinder.origin, cylinder.normal);
	// b = temp1 * temp2;
	// b = 2 * temp1 * temp2;
	// c = temp2 * temp2 - cylinder.radius * cylinder.radius;
	return (find_quadratic_formula(a, b, c));
}

t_float	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	t_float	dist_cap;
	t_float dist_body;
	t_float ignore;

	ignore = 0.001;
	dist_cap = hit_cylinder_cap(cylinder, ray);
	dist_body = hit_cylinder_body(cylinder, ray);
	if (dist_cap > ignore && (dist_body < ignore || dist_cap < dist_body))
		return (dist_cap);
	else if (dist_body > ignore && (dist_cap < ignore || dist_body < dist_cap))
		return (dist_body);
	return (-1);
}
