/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:53:31 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 22:53:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# include "t_float.h"

struct s_setting
{
	int		row_resolution_render;
	int		render_resolution_x;
	int		render_resolution_y;
	int		use_dot_light_rgb;
	int		use_dot_light_specular;
	int		use_dot_light_diffuse;
	int		use_ambient;
	int		use_dist_lose;
	int		switch_phong_path;
	int		use_dist_show;
	int		use_normal_show;
	t_float	ignore_complict_distance;

	t_float	dot_light_diffuse_ratio;
	t_float	dot_light_specular_ratio;
	t_float	ambient_ratio;

	t_float	bump_ratio;
};

#endif