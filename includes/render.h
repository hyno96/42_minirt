/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:37:16 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 17:10:52 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "float.h"
# include "vec3.h"
# include "ray.h"
# include "objects.h"

typedef struct s_hit_record	t_hit_record;

struct s_hit_record
{
	t_float		dist;
	t_point3	hit_point;
	t_vec3		normal_unit;
	t_surf		surf;
};

int	complict(t_ray ray, t_data data, t_hit_record *hit_record);
t_color3	trace_dot_light( \
	t_point3	shoot_coord, t_vec3 specular, t_vec3 normal_unit, t_data data);
t_color3 get_color_phong(t_ray ray, t_data data);
void	render_image_one(t_ray **ray_arr, t_color3 **screen, t_data data);
void	draw_screen(t_color3 **screen, t_data data);

#endif