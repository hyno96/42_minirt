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

// dev_comment_hyno
// static t_color3	get_plane(t_hit_record record)
// {
// 	t_plane plane;
// 	t_vec3	origin;

// 	plane = *conv_pl(record.obj);
// }

t_color3	get_color_checker(t_hit_record record)
{
	if (record.obj->type == SP)
		return (get_sphere(record));
	return (vec3(230, 210, 190));
}
