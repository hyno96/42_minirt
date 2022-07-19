#include "vec3.h"
#include "render.h"
#include "ray.h"
#include "structure.h"
#include "mapping_f.h"
#include "checkerboard_f.h"

static t_color3	normal_show(t_vec3 normal)
{
	normal = vec3_mult_scalar(normal, 100);
	if (normal.x < 0)
		normal.x *= -1;
	if (normal.y < 0)
		normal.y *= -1;
	if (normal.z < 0)
		normal.z *= -1;
	normal.x = (int)normal.x % 256;
	normal.y = (int)normal.y % 256;
	normal.z = (int)normal.z % 256;
	return (normal);
}

static t_color3	dist_show(t_float dist)
{
	dist *= 10;
	dist += 100;
	dist = (int)dist % 255;
	return (vec3(dist, dist, dist));
}

static void	apply_surf_color(t_vec3 *rtn_color, t_hit_record rec)
{
	if (rec.surf.use_ctc == 1)
		*rtn_color = vec3_mult(\
		*rtn_color, vec3_div(get_color_in_texture(rec), 255));
	else if (rec.surf.use_ctc == 2)
		*rtn_color = vec3_mult(\
			*rtn_color, vec3_div(get_color_checker(rec), 255));
	else
		*rtn_color = vec3_mult(*rtn_color, vec3_div(rec.surf.color, 255));
}

t_color3	get_color_phong(t_ray ray, t_data data)
{
	t_hit_record	record;
	t_vec3			specular_direction;
	t_point3		rtn_color;

	ray.direction = vec3_unit(ray.direction);
	if (complict(ray, data, &record) == TRUE)
	{
		if (data.setting->use_dist_show != FALSE)
			return (dist_show(record.dist));
		if (data.setting->use_normal_show != FALSE)
			return (normal_show(record.normal_unit));
		if (vec3_dot(record.normal_unit, ray.direction) > 0)
			record.normal_unit = vec3_mult_scalar(record.normal_unit, -1);
		specular_direction = vec3_minus(ray.direction, vec3_mult_scalar(\
			record.normal_unit, \
			2.0 * vec3_dot(ray.direction, record.normal_unit)));
		rtn_color = trace_dot_light(\
			record.hit_point, specular_direction, record.normal_unit, data);
		if (data.setting->use_ambient)
			rtn_color = vec3_plus(rtn_color, \
				vec3_mult_scalar(data.ambient, data.setting->ambient_ratio));
		apply_surf_color(&rtn_color, record);
		return (rtn_color);
	}
	return (vec3(100, 0, 0));
}
