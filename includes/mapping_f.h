/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:56:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 22:56:21 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_F_H
# define MAPPING_F_H

# include "vec3.h"
# include "image.h"
# include "t_float.h"
# include "objects.h"
# include "structure.h"

t_bool		load_image(char	*filename, t_img *image, t_data data);
void		get_xy_mapping_sphere(\
	t_float *x, t_float *y, t_vec3 normal_unit);
void		get_xy_mapping_plane(\
	t_float *x, t_float *y, t_point3 hitt, t_plane pl);
void		get_xy_mapping_cylinder(\
	t_float *x, t_float *y, t_hit_record rec, t_cylinder cy);
void		get_xy_mapping_cone(\
	t_float *x, t_float *y, t_hit_record rec, t_cone cn);
t_color3	get_color_texture(t_hit_record record);
t_color3	get_color_bumpmap(t_hit_record record);

#endif