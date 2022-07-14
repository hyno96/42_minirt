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

#include <stdio.h>

static t_color3	my_mlx_pixel_get(int x, int y, t_img image)
{
	char	*dst;
	unsigned int uint;

	dst = image.data_addr + \
		(y * image.size_line + x * (image.bits_per_pixel / 8));
	uint = *(unsigned int *)dst;
	// uint = (unsigned int)((image.data_addr)[x + image.x * y]);
	//uint = (unsigned int)(image.data_addr + \
	//	(y * image.size_line + x * (image.bits_per_pixel / 8)));
	//printf("%d %d\n", x, y);
	return (vec3((uint >> 16) % 256, (uint >> 8) % 256, uint % 256));
}

void	get_xy_mapping_sphere(\
	t_float *x, t_float *y, t_vec3 normal_unit, t_sphere sp)
{
	t_float cos_theta;
	static t_vec3	origin;
	t_vec3	xy_vec;

	if (origin.x == 0 && origin.z == 0)
		origin = vec3_unit(vec3(0, 0, -0.6));
	xy_vec = vec3_unit(vec3(normal_unit.x, 0 ,normal_unit.z));
	// cos_theta = vec3_dot(origin, xy_vec);
	// if (cos_theta < 0)
	// 	cos_theta = (-cos_theta + 1) / 2;
	// else
	// 	cos_theta = (1 - cos_theta) / 2;
	// if (vec3_cross(origin, xy_vec).y > 0)
	// 	*x = cos_theta / 2;
	// else
	// 	*x = (1 - (cos_theta / 2));
	cos_theta = acos(vec3_dot(origin, xy_vec));
	cos_theta /= M_PI;
	if (vec3_cross(origin, xy_vec).y > 0)
		*x = cos_theta / 2;
	else
		*x = (1 - (cos_theta / 2));
	*y = acos(vec3_dot(vec3(0, 1, 0), normal_unit)) / M_PI; 
	//printf("%f %f\n", *x, *y);
}

static t_color3	get_color_in_image(t_float x, t_float y, t_img image)
{
	t_vec3 vec;

	vec = my_mlx_pixel_get((t_float)image.x * x, (t_float)image.y * y, image);
	return (vec);
}

t_bool	load_image(char	*filename, t_img *image, t_data data)
{
	image->img_ptr = 0;
	image->img_ptr = mlx_xpm_file_to_image(\
		data.window.mlx_ptr, filename, &(image->x), &(image->y));
	if (image->img_ptr == 0)
		return (FALSE);
	image->data_addr = mlx_get_data_addr(image->img_ptr, \
			&(image->bits_per_pixel), &(image->size_line), &(image->endian));
	return (TRUE);
}

t_color3	get_color_in_texture(t_hit_record record)
{
	t_float x;
	t_float y;

	if (record.obj->type == SP)
	{
		get_xy_mapping_sphere(&x, &y, record.normal_unit, *conv_sp(record.obj));
		return (get_color_in_image(x, y, record.surf.texture));
	}
	return (vec3(100, 50, 200));
}