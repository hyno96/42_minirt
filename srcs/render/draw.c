#include "structure.h"
#include "setting_f.h"
#include "mlx.h"

static void	my_mlx_pixel_put(int x, int y, int color, t_img image)
{
	char	*dst;

	dst = image.data_addr + \
		(y * image.size_line + x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	limit_color(t_color3 *color)
{
	if ((*color).x >= 255)
		(*color).x = 255;
	if ((*color).y >= 255)
		(*color).y = 255;
	if ((*color).z >= 255)
		(*color).z = 255;
}

static int	get_int_color(t_color3 color)
{
	int	int_color;

	int_color = (int)color.x << 16;
	int_color += (int)color.y << 8;
	int_color += (int)color.z;
	return (int_color);
}

static void	draw_image_loop(t_color3 **screen, t_img image, t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.window.resolution_y)
	{
		j = 0;
		while (j < data.window.resolution_x)
		{
			limit_color(&screen[i][j]);
			my_mlx_pixel_put(j, i, get_int_color(screen[i][j]), image);
			j++;
		}
		i++;
	}
}

void	draw_screen(t_color3 **screen, t_data data)
{
	static t_img	image;

	if (image.img_ptr == 0)
	{
		image.img_ptr = mlx_new_image(data.window.mlx_ptr, \
			data.window.resolution_x, data.window.resolution_y);
		image.data_addr = mlx_get_data_addr(image.img_ptr, \
			&image.bits_per_pixel, &image.size_line, &image.endian);
	}
	draw_image_loop(screen, image, data);
	mlx_put_image_to_window(data.window.mlx_ptr, \
		data.window.win_ptr, image.img_ptr, 0, 0);
}
