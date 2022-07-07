#include "minirt.h"

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
static void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	get_color_temp(t_ray ray)
{
	float t;
	t_vec3 crossing;
	t_vec3 temp;

	t = (500 - ray.point.z) / ray.direction.z;
	ft_vec3_multi_float(&temp, t, &(ray.direction));
	ft_vec3_add(&crossing, &(ray.point), &temp);

	int recsize = 200;

	// if (crossing.x <= recsize && crossing.x >= -recsize && crossing.y <= recsize && crossing.y >= -recsize)
	// 	return ((255 << 16) + 0 + 0);
	if (crossing.x * crossing.x + crossing.y * crossing.y <= recsize * recsize)
		return ((255 << 16) + 0 + 0);
	return (0);
}

float hit_sphere(t_vec3 center, float radius, t_ray r) {
    t_vec3 oc;
	
	ft_vec3_set_xyz(&oc, r.point.x - center.x ,r.point.y - center.y ,r.point.z - center.z);
    float a = ft_vec3_dot(&(r.direction), &(r.direction));
    float b = 2.0 * ft_vec3_dot(&oc, &(r.direction));
    float c = ft_vec3_dot(&oc, &oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return (-1);
	float rtn = (-b + (float)sqrt(discriminant))/ (2 * a);
	float rtn2 = (-b - (float)sqrt(discriminant))/ (2 * a);

	float temp;

	if (rtn2 < 0 && rtn < 0)
		return (-1);
	if (rtn2 > rtn)
	{
		temp = rtn2;
		rtn2 = rtn;
		rtn = temp;
	}
	if (rtn2 > 0)
		return (rtn2);
	return (rtn);
}

static float	abs_float(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static float	hit_plane(t_object *plane, t_ray ray)
{
	float vn;
	float t;
	t_vec3 normal_vec;

	normal_vec = plane->normal;
	if (vec3_dot(normal_vec, ray.direction) < 0)
		normal_vec = vec3_mult_scalar(normal_vec, -1);

	vn = abs_float(vec3_dot(normal_vec, ray.direction));
	if (vn <= 0)
		return (-1);
	t = vec3_dot(vec3_div(vec3_minus(plane->coord, ray.point), vn), normal_vec);
	return (t);
}

static float	complict(t_ray ray, t_list	*list, t_object **object_hit)
{
	float	sol;
	float	temp;

	sol = 99999999;
	while (list)
	{
		if (conv_ob(list)->type == SPHERE || conv_ob(list)->type == MIRROR_SPHERE)
			temp = hit_sphere(conv_ob(list)->coord, conv_ob(list)->radius, ray);
		if (conv_ob(list)->type == PLANE)
			temp = hit_plane(conv_ob(list), ray);
		if (temp > 0.005)
		{
			if (temp < sol)
			{
				sol = temp;
				*object_hit = conv_ob(list);
			}
		}
		list = list->next;
	}
	if (sol != 99999999)
		return (sol);
	return (-1);
}

static int	get_color_temp2(t_ray ray, t_list *object_list)
{
	float t;
	t_object *object_hit;

	t = complict(ray, object_list, &object_hit);
	if (t > 0.1 && object_hit->type == 2)
		return (object_hit->color);
	return (0);
}

static float random_1()
{
	float a;
	a= (rand() - (RAND_MAX / 2)) / (float)RAND_MAX * 2;
	//printf("%f\n", a);
	return (a);
}

static t_vec3 random_unit_vector()
{
	t_vec3 rtn;
	while (1)
	{
		vec3_set(&rtn, random_1(), random_1(), random_1());
		if (vec3_len(rtn) <= 1)
			return (vec3_unit(rtn));
	}
}

static t_vec3 random_in_hemisphere(t_vec3 normal)
{
	t_vec3 rtn;
	rtn = random_unit_vector();
	if (vec3_dot(normal, rtn) < 0)
		return (rtn);
	else
	{
		return (vec3_mult_scalar(rtn, -1));
	}
}

static int find_light_and_get_lux(t_vec3 bumped, t_vec3 normal, t_rootdata *rootdata)
{
	int lux;
	float t;
	t_list *object_list;
	t_list *head;
	t_object *object_hit_from_ray;
	t_ray from_bump_to_light;

	float approach_angle;

	object_list = rootdata->object_list;

	float dist_bump_light;

	

	lux = 0;
	head = object_list;
	while (head)
	{
		if (conv_ob(head)->type == LIGHT)
		{
			from_bump_to_light.direction = vec3_minus(conv_ob(head)->coord, bumped);
			dist_bump_light = vec3_len(from_bump_to_light.direction);
			from_bump_to_light.direction = vec3_unit(from_bump_to_light.direction);
			from_bump_to_light.point = bumped;
			t = complict(from_bump_to_light, object_list, &object_hit_from_ray);
			//printf("%f %f\n ", t, dist_bump_light);
			if (t > dist_bump_light || t < 0)
			{
				approach_angle = vec3_dot(normal, from_bump_to_light.direction) / (vec3_len(from_bump_to_light.direction));
				lux += (int)((float)(conv_ob(head)->lux) * approach_angle / dist_bump_light);
			}
		}
		head = head->next;
	}
	return (lux);
}

static int get_color_temp3(t_ray ray, t_rootdata *rootdata, int depth)
{
	float t;
	t_object *object_hit;

	t_ray bounce;
	t_vec3 normal_vec;

	int rtn_color;
	int color_old;
	

	if (depth == 0)
	{
		//write(1,"1",1);
		return (0);
	}

	t = complict(ray, rootdata->object_list, &object_hit);
	if (t > 0.01)
	{
		
		if (object_hit->type == SPHERE)
		{
			bounce.point = ray_at(ray, t);
			normal_vec = vec3_minus(bounce.point, object_hit->coord);
			normal_vec = vec3_unit(normal_vec);
			if (vec3_dot(normal_vec, ray.direction) > 0)
				normal_vec = vec3_mult_scalar(normal_vec, -1);

			//rtn_color = 0;
			//rtn_color = (int)((256 << 16) * (normal_vec.x)) + (int)((256 << 8) * (normal_vec.y)) + (int)((256 << 0) * (normal_vec.z));
			//rtn_color = (int)((127 << 16) * (normal_vec.x + 1)) + (int)((127 << 8) * (normal_vec.y + 1)) + (int)((127 << 0) * (normal_vec.z + 1));
			//return (rtn_color);

			bounce.direction = random_in_hemisphere(normal_vec);
			bounce.direction = random_unit_vector();
			if (vec3_dot(normal_vec, bounce.direction) < 0)
				bounce.direction = vec3_mult_scalar(bounce.direction, -1);
			color_old = get_color_temp3(bounce, rootdata, depth - 1);
			
			rtn_color = 0;
			//rtn_color += (int)(((float)(object_hit->color >> 16) /(float)256) *  (float)color_old) << 16;
			//rtn_color += (int)(((float)(object_hit->color >> 8 % 256) /(float)256) *  (float)color_old) << 8;
			//rtn_color += (int)(((float)(object_hit->color % 256) /(float)256) *  (float)color_old) << 0;
			//return (rtn_color);

			float approach_angle = vec3_dot(normal_vec, bounce.direction) / (vec3_len(bounce.direction));
			//approach_angle = 1;

			int rtn_light = (int)((float)color_old * approach_angle * 0.7) + find_light_and_get_lux(bounce.point, normal_vec, rootdata);
			return (rtn_light * 0.5);

			//return ((float)color_old * 0.5);
		}
		else if (object_hit->type == MIRROR_SPHERE)
		{
			bounce.point = ray_at(ray, t);
			normal_vec = vec3_minus(bounce.point, object_hit->coord);
			normal_vec = vec3_unit(normal_vec);
			if (vec3_dot(normal_vec, ray.direction) > 0)
				normal_vec = vec3_mult_scalar(normal_vec, -1);
			bounce.direction = vec3_minus(ray.direction, vec3_mult_scalar(normal_vec, 2 * vec3_dot(ray.direction, normal_vec)));
			color_old = get_color_temp3(bounce, rootdata, depth - 1);

			// float approach_angle = vec3_dot(normal_vec, ray.direction) / vec3_dot(normal_vec, normal_vec);
			// if (approach_angle < 0)
			// 	approach_angle *= -1;
			// return ((float)color_old * approach_angle);
			return ((float)color_old * 0.5);
		}
		else if (object_hit->type == PLANE)
		{
			bounce.point = ray_at(ray, t);
			normal_vec = object_hit->normal;
			if (vec3_dot(normal_vec, ray.direction) > 0)
				normal_vec = vec3_mult_scalar(normal_vec, -1);

			bounce.direction = random_in_hemisphere(normal_vec);
			bounce.direction = random_unit_vector();
			if (vec3_dot(normal_vec, bounce.direction) < 0)
				bounce.direction = vec3_mult_scalar(bounce.direction, -1);

			color_old = get_color_temp3(bounce, rootdata, depth - 1);

			rtn_color = 0;
			//rtn_color += (int)(((float)(object_hit->color >> 16) /(float)256) *  (float)color_old) << 16;
			//rtn_color += (int)(((float)(object_hit->color >> 8 % 256) /(float)256) *  (float)color_old) << 8;
			//rtn_color += (int)(((float)(object_hit->color % 256) /(float)256) *  (float)color_old) << 0;
			//return (rtn_color);

			float approach_angle = vec3_dot(normal_vec, bounce.direction) / (vec3_len(bounce.direction));
			//approach_angle = 1;
			int rtn_light = (int)((float)color_old * approach_angle * 0.7) + find_light_and_get_lux(bounce.point, normal_vec, rootdata);
			return (rtn_light);
		}
	}
	//printf("%d\n", depth);
	//return ((30 << 16) + (90 << 8) + 120);
	return (20);
	
	// 충돌이 참이면
		// return (재귀함수에서 받는 컬러와 현재 컬러를 합병);
	// 배경색 반환 or 조명반환
}

static void	set_ray_from_viewport(t_ray *ray1, t_viewport *viewport, float x, float y)
{
	ray1->point.x = 0;
	ray1->point.y = 0;
	ray1->point.z = 0;
	ray1->direction.x = (x - (viewport->resolution_x / 2)) * viewport->interval_x + viewport->interval_x / 2;
	ray1->direction.y = ((viewport->resolution_y / 2) - y) * viewport->interval_y + viewport->interval_y / 2;
	ray1->direction.z = viewport->z_dist;
	(ray1->direction) = vec3_unit((ray1->direction));
}

void	*expose(t_rootdata *rootdata)
{
	t_data	image;
	t_mlx_data *mlxdata;
	int color;
	t_ray ray1;

	mlxdata = rootdata->mlx_data;
	image.img = mlx_new_image(mlxdata->mlx_ptr, mlxdata->resolution_x, mlxdata->resolution_y); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	int map[mlxdata->resolution_y][mlxdata->resolution_x];

	int repeat = 10;

	for (int i = 0 ; i < mlxdata->resolution_y ; i++)
	{
		for (int j = 0 ; j < mlxdata->resolution_x ; j++)
		{
			map[i][j] = 0;
		}
	}

	for (int k = 0; k < repeat; k++)
	{
		for (int i = 0 ; i < mlxdata->resolution_y ; i++)
		{
			for (int j = 0 ; j < mlxdata->resolution_x ; j++)
			{
				set_ray_from_viewport(&ray1, rootdata->viewport, j, i);
				color = get_color_temp3(ray1, rootdata, 20);
				//color = get_color_temp2(ray1, rootdata->object_list);
				color = color % 256;
				//color = (color << 16) + (color << 8) + color;
				map[i][j] += color;
				//my_mlx_pixel_put(&image, j, i, color);
				//my_mlx_pixel_put(&image, j, i, color);
				//write(1,"1",1);
			}
			//write(1,"\n\n",2);
		}

		// for (int i = 0 ; i < mlxdata->resolution_y ; i++)
		// {
		// 	for (int j = 0 ; j < mlxdata->resolution_x ; j++)
		// 	{
		// 		color = (int)(map[i][j] / (k + 1));
		// 		color = (color << 16) + (color << 8) + color;
		// 		my_mlx_pixel_put(&image, j, i, color);
		// 	}
		// 	//write(1,"\n\n",2);
		// }
		// mlx_put_image_to_window(rootdata->mlx_data->mlx_ptr, rootdata->mlx_data->win_ptr, image.img, 0, 0);
		// usleep(1000);
	}

		for (int i = 0 ; i < mlxdata->resolution_y ; i++)
		{
			for (int j = 0 ; j < mlxdata->resolution_x ; j++)
			{
				map[i][j] /= repeat;
				map[i][j] = (map[i][j] << 16) + (map[i][j] << 8) + map[i][j];
				my_mlx_pixel_put(&image, j, i, map[i][j]);
			}
			//write(1,"\n\n",2);
		}
	


	return (image.img);
}

int	**expose2(t_rootdata *rootdata)
{
	int **map;

	int color;
	t_ray ray1;

	map = malloc(sizeof(int*) * rootdata->mlx_data->resolution_y);
	for (int i = 0; i < rootdata->mlx_data->resolution_y; i++)
	{
		map[i] = malloc(sizeof(int) * rootdata->mlx_data->resolution_x);
	}

	for (int i = 0 ; i < rootdata->mlx_data->resolution_y ; i++)
	{
		for (int j = 0 ; j < rootdata->mlx_data->resolution_x ; j++)
		{
			map[i][j] = 0;
		}
	}

	for (int i = 0 ; i < rootdata->mlx_data->resolution_y ; i++)
	{
		for (int j = 0 ; j < rootdata->mlx_data->resolution_x ; j++)
		{
			if (i == 10 && j == 400)
				printf("stop");
			set_ray_from_viewport(&ray1, rootdata->viewport, j, i);
			color = get_color_temp3(ray1, rootdata, 10);
			//color = get_color_temp2(ray1, rootdata->object_list);
			// if (color > 255)
			// 	color = 255;
			//color = color % 256;
			//color = (color << 16) + (color << 8) + color;
			map[i][j] += color;
			//my_mlx_pixel_put(&image, j, i, color);
			//my_mlx_pixel_put(&image, j, i, color);
			//write(1,"1",1);
		}
		//write(1,"\n\n",2);
	}
	return (map);
}
