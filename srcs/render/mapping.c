#include "t_float.h"
#include "vec3.h"
#include "structure.h"
#include "objects.h"
#include "vec3.h"
#include "image.h"
#include "mlx.h"
#include "render.h"
#include "objects_f.h"
#include <math.h>

void	get_xy_mapping_sphere(\
	t_float *x, t_float *y, t_vec3 normal_unit, t_sphere sp)
{
	t_float			cos_theta;
	static t_vec3	origin;
	t_vec3			xy_vec;

	if (origin.x == 0 && origin.z == 0)
		origin = vec3_unit(vec3(0.5, 0, -1));
	xy_vec = vec3_unit(vec3(normal_unit.x, 0, normal_unit.z));
	cos_theta = acos(vec3_dot(origin, xy_vec));
	cos_theta /= M_PI;
	if (vec3_cross(origin, xy_vec).y > 0)
		*x = cos_theta / 2;
	else
		*x = (1 - (cos_theta / 2));
	*y = acos(vec3_dot(vec3(0, 1, 0), normal_unit)) / M_PI;
}

void	get_xy_mapping_plane(\
	t_float *x, t_float *y, t_point3 hitt, t_plane pl)
{
	*x = vec3_dot(pl.orivec_right, hitt);
	*y = vec3_dot(pl.orivec_top, hitt);
}

static void	cylinder_body_mapping(\
	t_float *x, t_float *y, t_hit_record rec, t_cylinder cy)
{
	t_float	cos_theta;

	cos_theta = acos(vec3_dot(cy.orivec_top, rec.normal_unit)) / M_PI;
	if (vec3_dot(cy.orivec_right, rec.normal_unit) < 0)
		*x = cos_theta / 2;
	else
		*x = (1 - (cos_theta / 2));
	*y = (rec.perpen + 2 * cy.radius) / (4 * cy.radius + cy.height);
}

void	get_xy_mapping_cylinder(\
	t_float *x, t_float *y, t_hit_record rec, t_cylinder cy)
{
	t_float	r;
	t_float	p2r;

	r = cy.radius;
	p2r = M_PI * 2 * r;
	if (rec.perpen < 0.001)
	{
		*x = (p2r - r + vec3_dot(cy.orivec_right, \
			vec3_minus(rec.hit_point, cy.origin))) / (p2r);
		*y = (vec3_dot(cy.orivec_top, \
			vec3_minus(rec.hit_point, cy.origin)) + r) / (4 * r + cy.height);
	}
	else if (rec.perpen > cy.height - 0.001)
	{
		*x = (r + vec3_dot(cy.orivec_right, \
			vec3_minus(rec.hit_point, cy.origin))) / (p2r);
		*y = (vec3_dot(cy.orivec_top, \
			vec3_minus(rec.hit_point, cy.origin)) + r) / (4 * r + cy.height);
	}
	else
		cylinder_body_mapping(x, y, rec, cy);
}
