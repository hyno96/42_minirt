#include "structure.h"
#include "vec3.h"
#include "ray.h"
#include <stdlib.h>
#include "setting_f.h"
#include "render.h"
#include "perror.h"
#include "objects.h"
#include "vec3.h"
#include "t_float.h"
#include "mapping_f.h"
#include "mlx_window.h"
#include "objects_f.h"
#include "../includes/hyno_main.h"

static void	malloc_screen(t_color3 ***target, int x, int y)
{
	int			i;
	t_color3	**screen;

	screen = 0;
	screen = (t_color3 **)malloc(sizeof(t_color3 *) * y);
	if (screen == 0)
	{
		ft_perror("malloc failed");
		exit(1);
	}
	i = 0;
	while (i < y)
	{
		screen[i] = 0;
		screen[i] = (t_color3 *)malloc(sizeof(t_color3) * x);
		if (screen[i] == 0)
		{
			ft_perror("malloc failed");
			exit(1);
		}
		i++;
	}
	*target = screen;
}

static void	malloc_ray(t_ray ***target, int x, int y)
{
	int		i;
	t_ray	**ray_arr;

	ray_arr = 0;
	ray_arr = (t_ray **)malloc(sizeof(t_ray *) * y);
	if (ray_arr == 0)
	{
		ft_perror("malloc failed");
		exit(1);
	}
	i = 0;
	while (i < y)
	{
		ray_arr[i] = 0;
		ray_arr[i] = (t_ray *)malloc(sizeof(t_ray) * x);
		if (ray_arr[i] == 0)
		{
			ft_perror("malloc failed");
			exit(1);
		}
		i++;
	}
	*target = ray_arr;
}

void	hyno_test(t_data data)
{
	t_ray		**ray_arr;
	t_color3	**screen;

	data.window.resolution_x = WIDTH;
	data.window.resolution_y = HEIGHT;
	setting_default(&data);
	set_orivec(data.object_list);
	malloc_ray(&ray_arr, data.setting->render_resolution_x, \
		data.setting->render_resolution_y);
	malloc_screen(&screen, data.setting->render_resolution_x, \
		data.setting->render_resolution_y);
	render_image_one(ray_arr, screen, data);
	draw_screen(screen, data);
	free_myarr(ray_arr, screen);
}
