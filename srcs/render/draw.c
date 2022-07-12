/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:07:36 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 16:25:33 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

static void	my_mlx_pixel_put(int x, int y, int color, t_img image)
{
	char	*dst;

	dst = image.data_addr + \
		(y * image.size_line + x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	row_resoultion_draw(int ij[2], int row, int color, t_img image)
{
	int	i;
	int	j;

	while (i < row)
	{
		j = 0;
		while (j < row)
		{
			my_mlx_pixel_put(ij[1] + j, ij[1] + i, color, image);
			j++;
		}
		i++;
	}
}

static void	draw_image_loop(t_color3 **screen, t_img image, t_data data)
{
	int	ij[2];
	int	color;

	ij[0] = 0;
	while (ij[0] < data.window.resolution_y)
	{
		ij[1] = 0;
		while (ij[1] < data.window.resolution_y)
		{
			color = screen[ij[1]][ij[0]].x;
			color += screen[ij[1]][ij[0]].y;
			color += screen[ij[1]][ij[0]].z;
			row_resoultion_draw(ij, data.setting->row_resolution_render, \
				color, image);
			ij[1]++;
		}
		ij[0]++;
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
