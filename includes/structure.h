/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:03:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 17:40:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "vec3.h"
# include "libft.h"
# include "t_float.h"
# include "setting.h"
# include "image.h"

typedef struct s_window			t_window;
typedef struct s_img			t_img;
typedef struct s_camera			t_camera;
typedef enum e_bool				t_bool;
typedef struct s_data			t_data;
typedef struct s_setting		t_setting;
typedef struct s_quadratic_eq	t_quadratic_eq;

struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	mlx_img;
	int		resolution_x;
	int		resolution_y;
};

enum e_bool
{
	FALSE,
	TRUE
};

struct s_camera
{
	t_point3	origin;
	t_vec3		direction;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_float		focal_len;
	t_point3	left_bottom;
};

struct s_data
{
	t_window	window;
	t_color3	ambient;
	t_camera	camera;
	t_list		*dot_lights;
	t_list		*object_list;
	t_setting	*setting;
};

struct s_quadratic_eq
{
	t_float	a;
	t_float	hb;
	t_float	c;
	t_float	d;
};

#endif