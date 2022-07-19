#include "t_float.h"
#include "vec3.h"
#include "structure.h"
#include "objects.h"
#include "vec3.h"
#include "image.h"
#include "mlx.h"
#include "render.h"
#include "objects_f.h"
#include "math.h"

static t_color3	my_mlx_pixel_get(int x, int y, t_img image)
{
	char			*dst;
	unsigned int	uint;

	dst = image.data_addr + \
		(y * image.size_line + x * (image.bits_per_pixel / 8));
	uint = *(unsigned int *)dst;
	return (vec3((uint >> 16) % 256, (uint >> 8) % 256, uint % 256));
}


static t_color3	get_color_in_image(t_float x, t_float y, t_img image)
{
	t_vec3	vec;

	vec = my_mlx_pixel_get((t_float)image.x * x, (t_float)image.y * y, image);
	return (vec);
}

t_color3	get_color_in_texture(t_hit_record record)
{
	t_float	x;
	t_float	y;

	if (record.obj->type == SP)
	{
		get_xy_mapping_sphere(&x, &y, record.normal_unit, *conv_sp(record.obj));
		return (get_color_in_image(x, y, record.surf.texture));
	}
	return (vec3(100, 50, 200));
}
