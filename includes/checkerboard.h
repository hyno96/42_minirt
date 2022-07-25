/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:54:16 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 22:54:59 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERBOARD_H
# define CHECKERBOARD_H

# include "structure.h"

typedef struct s_checkerboard
{
	t_float		x_range;
	t_float		y_range;
	t_color3	color1;
	t_color3	color2;
}t_checkerboard;

#endif