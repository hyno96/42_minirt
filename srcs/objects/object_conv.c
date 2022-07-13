/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:50:42 by hyno              #+#    #+#             */
/*   Updated: 2022/07/12 12:51:22 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"

t_sphere *conv_sp(t_list	*head)
{
	return ((t_sphere *)(head->content));
}

t_plane *conv_pl(t_list	*head)
{
	return ((t_plane *)(head->content));
}

t_cylinder *conv_cy(t_list	*head)
{
	return ((t_cylinder *)(head->content));
}

t_dot_light *conv_li(t_list	*head)
{
	return ((t_dot_light *)(head->content));
}
