#include "structure.h"
#include "perror.h"
#include "ray.h"
#include "setting_f.h"
#include "render.h"

void	set_ray(t_ray **ray_arr, t_data data)
{
	int			i;
	int			j;
	int			interval;
	t_camera	camera;

	interval = data.setting->row_resolution_render;
	camera = (data.camera);
	i = 0;
	while (i < data.setting->render_resolution_y)
	{
		j = 0;
		while (j < data.setting->render_resolution_x)
		{
			ray_arr[i][j].point = camera.origin;
			ray_arr[i][j].direction = vec3_plus(camera.left_bottom, vec3_plus(\
				vec3_mult_scalar(camera.horizontal, j * interval), \
				vec3_mult_scalar(camera.vertical, i * interval)));
			j++;
		}
		i++;
	}
}

void	render_image_one(t_ray **ray_arr, t_color3 **screen, t_data data)
{
	int			i;
	int			j;

	set_ray(ray_arr, data);
	i = 0;
	while (i < data.setting->render_resolution_y)
	{
		j = 0;
		while (j < data.setting->render_resolution_x)
		{
			if (i == 540 && j == 960)
				i += 0;
			if (data.setting->switch_phong_path == 0)
				screen[data.setting->render_resolution_y - 1 - i][j] = \
				get_color_phong(ray_arr[i][j], data);
			j++;
		}
		i++;
	}
}
