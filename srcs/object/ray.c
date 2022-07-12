/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:29:31 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 13:29:32 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "float.h"
#include "ray.h"
#include "vec3.h"

t_point3	ray_at(t_ray ray, t_float t)
{
	return (vec3_plus(ray.point ,vec3_mult_scalar(ray.direction, t)));
}