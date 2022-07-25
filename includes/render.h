/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:37:16 by hyno              #+#    #+#             */
/*   Updated: 2022/07/25 22:52:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "float.h"
# include "vec3.h"
# include "ray.h"
# include "objects.h"
# include "libft.h"

typedef struct s_hit_record	t_hit_record;

struct s_hit_record
{
	t_float		dist;
	t_point3	hit_point;
	t_point3	hit_point_old;
	t_vec3		normal_unit;
	t_surf		surf;
	t_list		*obj;
	t_float		perpen;
	t_vec3		perpen_at;
};

int			complict(t_ray ray, t_data data, t_hit_record *hit_record);
t_color3	trace_dot_light(t_point3 origin, \
					t_vec3 specular, t_vec3 normal_unit, t_data data);
t_color3	get_color_phong(t_ray ray, t_data data);
void		render_image_one(t_ray **ray_arr, t_color3 **screen, t_data data);
void		draw_screen(t_color3 **screen, t_data data);
void		set_hit_record_cn(t_cone *cn, t_hit_record *rec);

#endif