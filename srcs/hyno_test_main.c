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

static void	malloc_screen(t_color3 ***target, int x, int y)
{
	int		i;
	t_color3	**screen;

	screen = 0;
	screen = (t_color3 **)malloc(sizeof(t_color3 *) * y);
	if (screen == 0)
		ft_perror("malloc failed");
	i = 0;
	while (i < y)
	{
		screen[i] = 0;
		screen[i] = (t_color3 *)malloc(sizeof(t_color3) * x);
		if (screen[i] == 0)
			ft_perror("malloc failed");
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
		ft_perror("malloc failed");
	i = 0;
	while (i < y)
	{
		ray_arr[i] = 0;
		ray_arr[i] = (t_ray *)malloc(sizeof(t_ray) * x);
		if (ray_arr[i] == 0)
			ft_perror("malloc failed");
		i++;
	}
	*target =ray_arr;
}

// t_sphere	*new_sphere(t_vec3 origin, t_float radius, t_color3 color, t_data data)
// {
// 	t_sphere *rtn;

// 	rtn = malloc(sizeof(t_sphere));
// 	rtn->origin = origin;
// 	rtn->radius = radius;
// 	rtn->surf.color = color;
// 	rtn->surf.use_ctc = load_image("earthmap1k.xpm", &(rtn->surf.texture), data);
// 	return (rtn);
// }

// t_sphere	*new_sphere_c(t_vec3 origin, t_float radius, t_color3 color, t_data data)
// {
// 	t_sphere *rtn;

// 	rtn = malloc(sizeof(t_sphere));
// 	rtn->origin = origin;
// 	rtn->radius = radius;
// 	rtn->surf.color = color;
// 	rtn->surf.use_ctc = 2;
// 	rtn->surf.checker.x_range = 1;
// 	rtn->surf.checker.y_range = 1;
// 	rtn->surf.checker.color1 = vec3(180, 100 ,30);
// 	rtn->surf.checker.color2 = vec3(25, 88, 130);
// 	return (rtn);
// }

// t_plane	*new_plane(t_vec3 origin, t_vec3 normal, t_color3 color)
// {
// 	t_plane *rtn;

// 	rtn = malloc(sizeof(t_plane));
// 	rtn->origin = origin;
// 	rtn->normal = normal;
// 	rtn->surf.color = color;
// 	// rtn->surf.use_ctc = 2;
// 	// rtn->surf.checker.x_range = 1;
// 	// rtn->surf.checker.y_range = 1;
// 	// rtn->surf.checker.color1 = vec3(180, 100 ,30);
// 	// rtn->surf.checker.color2 = vec3(25, 88, 130);
// 	return (rtn);
// }

// t_dot_light	*new_dot_light(t_vec3 origin, int color)
// {
// 	t_dot_light *rtn;

// 	rtn = malloc(sizeof(t_dot_light));
// 	rtn->origin = origin;
// 	rtn->color.x = color;
// 	rtn->color.y = color;
// 	rtn->color.z = color;
// 		return (rtn);
// }

// t_list	*ft_lstnew_type(void *content, int type)
// {
// 	t_list	*rtn;
	
// 	rtn = malloc(sizeof(t_list));
// 	rtn->content = content;
// 	rtn->next = 0;
// 	rtn->type = type;
// 	return (rtn);
// }

void	hyno_test(t_data data)
{
	t_ray		**ray_arr;
	t_color3	**screen;

	// ft_lstadd_front(&data.object_list, ft_lstnew_type(new_sphere(vec3(0,0, -2), 0.5, vec3(200, 100, 50), data), SP));
	// ft_lstadd_front(&data.object_list, ft_lstnew_type(new_sphere_c(vec3(-1,1,-3), 1, vec3(10, 10, 200), data), SP));

	// //ft_lstadd_front(&data.object_list, ft_lstnew_type(new_plane(vec3(0, 2, 0), vec3(0,1,0), vec3(255, 155, 55)), PL));
	// //ft_lstadd_front(&data.object_list, ft_lstnew_type(new_plane(vec3(0, 0, -10), vec3_unit(vec3(0,0,1)), vec3(0, 255, 10)), PL));
	// ft_lstadd_front(&data.object_list, ft_lstnew_type(new_plane(vec3(0, -1, 0), vec3_unit(vec3(0, 1,0)), vec3(255, 155, 55)), PL));

	
	// //ft_lstadd_front(&data.dot_lights, ft_lstnew_type(new_dot_light(vec3(0, 2, -1), 1000), 0));
	// ft_lstadd_front(&data.dot_lights, ft_lstnew_type(new_dot_light(vec3(0, 0, 1), 1000), 0));

	// data.camera.origin = vec3(0, 0, 0);
	// data.ambient = vec3(0 , 20, 0);
	// data.camera.direction = vec3(0, 0, -1);
	// data.camera.horizontal = vec3(1, 0, 0);
	// data.camera.vertical = vec3(0, 1, 0);
	// data.camera.focal_len = 1;
	// data.camera.left_bottom = vec3(-960, -540, -800);

	data.window.resolution_x = WIDTH;
	data.window.resolution_y = HEIGHT;
	setting_default(&data);
	malloc_ray(&ray_arr, data.setting->render_resolution_x, \
		data.setting->render_resolution_y);
	malloc_screen(&screen, data.setting->render_resolution_x, \
		data.setting->render_resolution_y);
	render_image_one(ray_arr, screen, data);
	draw_screen(screen, data);
}
