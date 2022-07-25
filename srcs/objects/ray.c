/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:17:39 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:17:40 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "float.h"
#include "vec3.h"

t_point3	ray_at(t_ray ray, t_float t)
{
	return (vec3_plus(ray.point, vec3_mult_scalar(ray.direction, t)));
}

t_ray	ray(t_vec3 point, t_vec3 direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}
