/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:46:23 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 18:21:08 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "perror.h"
#include "ray.h"
#include "setting.h"
#include "render.h"

// dev_comment_hyno
// 레이 배열에 카메라의 상태에 따라서 레이 값을 저장함
// 레이 배열은 오른손좌표계의 순서로 채워짐 (스크린과 다르다!!!)
void	set_ray(t_ray **ray_arr, t_data data)
{
	int			i;
	int			j;
	int			interval;
	t_camera	camera;

	interval = data.setting->row_resolution_render;
	camera = *(data.camera);
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

// dev_comment_hyno
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
			if (data.setting->switch_phong_path == 0)
				screen[data.setting->render_resolution_y - 1 - i][j] = \
				get_color_phong(ray_arr[i][j], data);
			//else
				//screen[i][j] = get_color_path(ray_arr[i][j], data);
			j++;
		}
		i++;
	}
}
