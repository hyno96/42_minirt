#include "checkerboard.h"
#include "render.h"
#include "objects_f.h"
#include "mapping_f.h"

static t_color3	get_sphere(t_hit_record record)
{
	t_sphere	sphere;
	t_vec3		origin;
	t_float		x;
	t_float		y;
	int			divide2;

	sphere = *conv_sp(record.obj);
	get_xy_mapping_sphere(&x, &y, record.normal_unit, sphere);
	divide2 = (int)(2 * M_PI * sphere.radius * x / record.surf.checker.x_range);
	divide2 += (int)(M_PI * sphere.radius * y / record.surf.checker.y_range);
	if (divide2 % 2 == 0)
		return (record.surf.checker.color1);
	return (record.surf.checker.color2);
}

static t_color3	get_plane(t_hit_record record)
{
	t_float	x;
	t_float	y;
	int		divide2;

	get_xy_mapping_plane(&x, &y, record.hit_point, *conv_pl(record.obj));
	if (x < 0)
		x += -1;
	if (y < 0)
		y += -1;
	divide2 = (int) x / record.surf.checker.x_range;
	divide2 += (int) y / record.surf.checker.y_range;
	if (divide2 % 2 == 0)
		return (record.surf.checker.color1);
	return (record.surf.checker.color2);
}

static t_color3	get_cylinder(t_hit_record record)
{
	t_float	x;
	t_float	y;
	int		divide2;

	get_xy_mapping_cylinder(&x, &y, record, *conv_cy(record.obj));
	divide2 = (int) (x * 2 * M_PI * conv_cy(record.obj)->radius) \
		/ record.surf.checker.x_range;
	divide2 += (int) (y * (4 * conv_cy(record.obj)->radius + \
		 conv_cy(record.obj)->height)) / record.surf.checker.y_range;
	if (divide2 % 2 == 0)
		return (record.surf.checker.color1);
	return (record.surf.checker.color2);
}

t_color3	get_color_checker(t_hit_record record)
{
	if (record.obj->type == SP)
		return (get_sphere(record));
	else if (record.obj->type == PL)
		return (get_plane(record));
	else if (record.obj->type == CY)
		return (get_cylinder(record));
	return (vec3(230, 210, 190));
}
