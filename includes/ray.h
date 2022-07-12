/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:47:11 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 13:29:35 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray	t_ray;

struct s_ray
{
	t_point3	point;
	t_vec3		direction;
	float		refractive;
};

t_point3	ray_at(t_ray ray, t_float t);

#endif
