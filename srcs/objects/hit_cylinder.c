#include "t_float.h"
#include "vec3.h"
#include "objects_f.h"

static t_float	hit_cylinder_cap(t_cylinder cylinder, t_ray myray)
{
	t_float	dist_cap1;
	t_float	dist_cap2;
	t_vec3	temp_rayat;
	t_float	ignore;
	t_vec3	origin2;

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
	return (find_small_solution(dist_cap1, dist_cap2));
}

static t_bool	is_on_cy(t_cylinder cy, t_vec3 rayat)
{
	t_point3	origin2;
	t_vec3		cy_to_rayat;

	origin2 = vec3_plus(cy.origin, vec3_mult_scalar(cy.normal, cy.height));
	cy_to_rayat = vec3_minus(rayat, origin2);
	if (vec3_dot(cy_to_rayat, cy.normal) / vec3_len(cy_to_rayat) > 0)
		return (FALSE);
	cy_to_rayat = vec3_minus(rayat, cy.origin);
	if (vec3_dot(cy_to_rayat, cy.normal) / vec3_len(cy_to_rayat) < 0)
		return (FALSE);
	return (TRUE);
}

// dev_comment_hyno
// 노말벡터를 사전에 유닛벡터화 할 것
static t_float	hit_cylinder_body(t_cylinder cylinder, t_ray ray)
{
	t_float	cal[3];
	t_vec3	tempvec;
	t_vec3	tempvec2;
	t_float	sol;

	tempvec = vec3_cross(ray.direction, cylinder.normal);
	cal[0] = vec3_dot(tempvec, tempvec);
	tempvec2 = vec3_cross(vec3_minus(ray.point, cylinder.origin), cylinder.normal);
	cal[1] = vec3_dot(tempvec, tempvec2) * 2.0;
	cal[2] = vec3_dot(tempvec2, tempvec2) - cylinder.radius * cylinder.radius;
	sol = find_quadratic_formula(cal[0], cal[1], cal[2]);
	if (is_on_cy(cylinder, ray_at(ray, sol)) == FALSE)
		sol = -1;
	return (sol);
}

t_float	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	t_float	dist_cap;
	t_float	dist_body;
	t_float	ignore;

	ignore = 0.001;
	dist_cap = hit_cylinder_cap(cylinder, ray);
	dist_body = hit_cylinder_body(cylinder, ray);
	return (find_small_solution(dist_cap, dist_body));
}
