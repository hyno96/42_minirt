/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:00:09 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 10:00:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include <mlx.h>
# include <stdlib.h>

# include "structure.h"

# define WIDTH  1000
# define HEIGHT 500
# define TITLE  "miniRT"

# define X11_KEYPRESS		2
# define X11_DESTROYNOTIFY	17
# define KEYPRESS_MASK		(1L)
# define NOEVENT_MASK		(0L)
# define ESC_KEY			53

t_bool	init_window(t_window *window);

#endif