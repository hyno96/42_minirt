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

#include <stdio.h>

static t_float	cone_body_mapping(t_float *x, t_float *y, t_hit_record rec, t_cone cn)
{
	t_float cos_theta;

	cos_theta = acos(vec3_dot(cn.orivec_top, rec.normal_unit)) / M_PI;
	if (vec3_dot(cn.orivec_right, rec.normal_unit) < 0)
		*x = cos_theta / 2;
	else
		*x = (1 - (cos_theta / 2));
	*y = (rec.perpen + 2 * cn.radius) / (4 * cn.radius + cn.height);
	// printf("%f	", *y);
}

void	get_xy_mapping_cone(\
	t_float *x, t_float *y, t_hit_record rec, t_cone cn)
{
	t_float r;
	t_float p2r;

	r = cn.radius;
	p2r = M_PI * 2 * r;
	if (rec.perpen < 0.001)
	{
		*x = (p2r - r + vec3_dot(cn.orivec_right, vec3_minus(rec.hit_point, cn.origin))) /  (p2r);
		*y = (vec3_dot(cn.orivec_top, vec3_minus(rec.hit_point, cn.origin)) + r) / (4 * r + cn.height);
	}
	else
		cone_body_mapping(x, y, rec, cn);
}