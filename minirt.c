#include "minirt.h"
#include "mlx/mlx.h"

//#include <mlx.h>

void	*expose(t_rootdata *rootdata);
int		**expose2(t_rootdata *rootdata);

void	set_rootdata(t_rootdata *rootdata)
{
	t_viewport *my_viewport;
	t_mlx_data *my_mlx_data;
	t_list		*my_list;
	t_vec3		tempvec;
	t_vec3		tempnormal;
	
	my_viewport = malloc(sizeof(t_viewport));
	rootdata->viewport = my_viewport;
	my_viewport->resolution_x = 1600;
	my_viewport->resolution_y = 900;
	my_viewport->interval_x = 1.2;
	my_viewport->interval_y = 1.2;
	my_viewport->z_dist = 500;

	my_mlx_data = malloc(sizeof(t_mlx_data));
	rootdata->mlx_data = my_mlx_data;
	my_mlx_data->mlx_ptr = mlx_init();
	my_mlx_data->resolution_x = my_viewport->resolution_x;
	my_mlx_data->resolution_y = my_viewport->resolution_y;
	rootdata->mlx_data->title_text = "babo";
	my_mlx_data->win_ptr = mlx_new_window(my_mlx_data->mlx_ptr, my_mlx_data->resolution_x, my_mlx_data->resolution_y, rootdata->mlx_data->title_text);
	my_mlx_data->pixelsize = 1;

	// ft_vec3_set_xyz(&tempvec, 30, 100, 500);
	// ft_lstadd_back(&my_list, ft_lstnew(new_sphere(tempvec, 180, (200 << 16) + (100 << 8))));
	ft_vec3_set_xyz(&tempvec, -400, 50, 500);
	ft_lstadd_back(&my_list, ft_lstnew(new_sphere(tempvec, 180, (180 << 16) + (180 << 8) + 180)));
	ft_vec3_set_xyz(&tempvec, -100, -70, 150);
	ft_lstadd_back(&my_list, ft_lstnew(new_mirror_sphere(tempvec, 30, (180 << 16) + (180 << 8) + 180)));
	// ft_vec3_set_xyz(&tempvec, -30, 500, 1800);
	// ft_lstadd_back(&my_list, ft_lstnew(new_mirror_sphere(tempvec, 1200, (180 << 16) + (180 << 8) + 180)));
	ft_vec3_set_xyz(&tempvec, 120, 40, 300);
	ft_lstadd_back(&my_list, ft_lstnew(new_sphere(tempvec, 60, (180 << 16) + (180 << 8) + 180)));
	// ft_vec3_set_xyz(&tempvec, 0, -10000, 0);
	// ft_lstadd_back(&my_list, ft_lstnew(new_sphere(tempvec, 9900, (180 << 16) + (180 << 8) + 180)));
	// ft_vec3_set_xyz(&tempvec, 0, 500, 300);
	// ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 100, 100, (255 <<16) + (255 << 8) + 255)));
	// ft_vec3_set_xyz(&tempvec, 100, 600, 300);
	// ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 50, 50, 255)));

	ft_vec3_set_xyz(&tempvec, -900, 900, 900);
	ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 50, 10000, 255)));
	ft_vec3_set_xyz(&tempvec, 0, 900, 900);
	ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 50, 10000, 255)));
	ft_vec3_set_xyz(&tempvec, 900, 900, 900);
	ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 50, 10000, 255)));


	// ft_vec3_set_xyz(&tempvec, 0, 100, -10);
	// ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 50, 80, 255)));

	// ft_vec3_set_xyz(&tempvec, 0, 50000, 0);
	// ft_lstadd_back(&my_list, ft_lstnew(new_light(tempvec, 22000, 200, 255)));
	// ft_vec3_set_xyz(&tempvec, 0, 40, -100);
	// ft_lstadd_back(&my_list, ft_lstnew(new_sphere(tempvec, 30, (100 << 8) + 200)));

	ft_vec3_set_xyz(&tempvec, 0, 0, 1000);
	ft_vec3_set_xyz(&tempnormal, 0, 0, 1);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	ft_vec3_set_xyz(&tempvec, 1000, 0, 0);
	ft_vec3_set_xyz(&tempnormal, 1, 0, 0);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	ft_vec3_set_xyz(&tempvec, -1000, 0, 0);
	ft_vec3_set_xyz(&tempnormal, -1, 0, 0);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	ft_vec3_set_xyz(&tempvec, 0, 0, -100);
	ft_vec3_set_xyz(&tempnormal, 0, 0, -1);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	ft_vec3_set_xyz(&tempvec, 0, -100, 0);
	ft_vec3_set_xyz(&tempnormal, 0, 1, 0);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	ft_vec3_set_xyz(&tempvec, 0, 1000, 0);
	ft_vec3_set_xyz(&tempnormal, 0, 1, 0);
	ft_lstadd_back(&my_list, ft_lstnew(new_plane(tempvec, tempnormal, 255)));

	rootdata->object_list = my_list;
}

static void			my_mlx_pixel_put1(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	abc(t_rootdata *rootdata)// 이벤트 발생시 call될 함수
{
	static int time;
	static int fullmap[900][1600];

	int **tempmap;

	t_data	image;
	int color;

	time++;

	image.img = mlx_new_image(rootdata->mlx_data->mlx_ptr, rootdata->mlx_data->resolution_x, rootdata->mlx_data->resolution_y); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	tempmap = expose2(rootdata);
	for (int i = 1 ; i < rootdata->mlx_data->resolution_y - 1; i++)
	{
		for (int j = 1 ; j < rootdata->mlx_data->resolution_x - 1; j++)
		{
			// fullmap[i][j] += tempmap[i][j] / 2 ;
			// fullmap[i][j] += tempmap[i + 1][j] / 8;
			// fullmap[i][j] += tempmap[i][j + 1] / 8;
			// fullmap[i][j] += tempmap[i - 1][j] / 8;
			// fullmap[i][j] += tempmap[i][j - 1] / 8;

			fullmap[i][j] += tempmap[i][j] ;
		}
	}

	free (tempmap);

	for (int i = 0 ; i < rootdata->mlx_data->resolution_y ; i++)
	{
		for (int j = 0 ; j < rootdata->mlx_data->resolution_x ; j++)
		{
			color = (int)(fullmap[i][j] / (time));
			if (color > 255)
				color = 255;
			color = (int)(sqrt(((float)color / 256)) * 256);

			color = (color << 16) + (color << 8) + color;
			my_mlx_pixel_put1(&image, j, i, color);
		}
		
	}
	printf("%d\n", time);
	rootdata->mlx_data->title_text = "good";
	mlx_put_image_to_window(rootdata->mlx_data->mlx_ptr, rootdata->mlx_data->win_ptr, image.img, 0, 0);
	mlx_string_put (rootdata->mlx_data->mlx_ptr, rootdata->mlx_data->win_ptr, 10, 25, 255, ft_itoa(time));

	return 0;
}

int main()
{
	t_rootdata rootdata;

	set_rootdata(&rootdata);

	void* img;

	//img = expose(&rootdata);
	//mlx_put_image_to_window(rootdata.mlx_data->mlx_ptr, rootdata.mlx_data->win_ptr, img, 0, 0);
	//mlx_key_hook(rootdata.mlx_data->win_ptr, abc, &rootdata);// 생성된 창에서 key입력 이벤트가 발생 시 close 함수를 실행한다.
	mlx_loop_hook(rootdata.mlx_data->mlx_ptr, abc, &rootdata);
	mlx_loop(rootdata.mlx_data->mlx_ptr);
	return (0);
}