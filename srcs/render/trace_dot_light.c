/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:45:15 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 14:57:12 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "structure.h"
#include "objects.h"
#include "ray.h"
#include "libft.h"

// dev_comment_hyno
// ft_lstnew 를 사용했으므로 말록가드 코드 추가 작성필요
t_list	*trace_dot_light(t_point3	shoot_coord, t_data data)
{
	t_list			*head;
	t_list			*hitt_dot_light_list;
	t_ray			ray;
	t_hit_record	record;

	hitt_dot_light_list = 0;
	head = data.dot_lights;
	while (head)
	{
		ray.point = shoot_coord;
		ray.direction = vec3_minus(conv_li(head)->origin, shoot_coord);
		if (complict(ray, data, &record) == 0 || \
			record.dist * record.dist > vec3_square_len(ray.direction))
		{
			ft_lstadd_front(hitt_dot_light_list, ft_lstnew(head));
		}
		head = head->next;
	}
	return (hitt_dot_light_list);
}

t_color3	get_specular_color_from_dot_light( \
	t_point3 shoot_coord, t_vec3 specular_direction, t_list *head)
{
	t_vec3		direction_to_light;
	t_color3	rtn_color;
	t_float		cos_theta;

	rtn_color = vec3(0, 0, 0);
	while (head)
	{
		direction_to_light = vec3_minus(conv_li(head)->origin, shoot_coord);
		cos_theta = vec3_dot(specular_direction, direction_to_light) / \
			(vec3_len(direction_to_light));
		cos_theta = cos_theta * cos_theta * cos_theta * cos_theta * cos_theta;
		rtn_color = vec3_plus(rtn_color, \
			vec3_mult_scalar(conv_li(head)->color, cos_theta));
		rtn_color = vec3_div();
		head = head->next;
	}
	return (rtn_color);
}

t_color3	get_diffuse_color_from_dot_light( \
	t_point3 shoot_coord, t_vec3 specular_direction, t_list *head)
{
	t_vec3		direction_to_light;
	t_color3	rtn_color;
	t_float		cos_theta;

	rtn_color = vec3(0, 0, 0);
	while (head)
	{
		direction_to_light = vec3_minus(conv_li(head)->origin, shoot_coord);
		cos_theta = vec3_dot(specular_direction, direction_to_light) / \
			(vec3_len(direction_to_light));
		cos_theta = cos_theta * cos_theta * cos_theta * cos_theta * cos_theta;
		rtn_color = vec3_plus(rtn_color, \
			vec3_mult_scalar(conv_li(head)->color, cos_theta));
		head = head->next;
	}
	return (rtn_color);
}
