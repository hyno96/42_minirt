/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:17:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:17:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"

t_sphere	*conv_sp(t_list	*head)
{
	return ((t_sphere *)(head->content));
}

t_plane	*conv_pl(t_list	*head)
{
	return ((t_plane *)(head->content));
}

t_cylinder	*conv_cy(t_list	*head)
{
	return ((t_cylinder *)(head->content));
}

t_dot_light	*conv_li(t_list	*head)
{
	return ((t_dot_light *)(head->content));
}

t_cone	*conv_cn(t_list *head)
{
	return ((t_cone *)(head->content));
}
