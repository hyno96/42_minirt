/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:32:02 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 16:47:54 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

typedef struct s_setting	t_setting;

struct s_setting
{
	int		row_resolution_render;
	int		render_resolution_x;
	int		render_resolution_y;
	int 	use_dot_light_rgb;
	int		use_dot_light_specular;
	int		use_dot_light_diffuse;
	int		use_ambient;
	int		switch_phong_path;
	t_float	ignore_complict_distance;

	t_float	dot_light_diffuse_ratio;
	t_float	dot_light_specular_ratio;
	t_float	ambient_ratio;
};

#endif