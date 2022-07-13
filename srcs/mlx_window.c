/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:47:31 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/12 18:26:48 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"


static int key_press(int keycode)
{
    if (keycode == ESC_KEY)
        exit(EXIT_SUCCESS);
    return (0);
}

static int click_red_cross(void)
{
    exit(EXIT_SUCCESS);
}

static void hook_event(t_window *window)
{
    mlx_hook(window->win_ptr, X11_KEYPRESS, KEYPRESS_MASK, key_press, NULL);
    mlx_hook(window->win_ptr, X11_DESTROYNOTIFY, NOEVENT_MASK, click_red_cross, NULL);
}

static t_bool  fail_to_window_init(t_window *window)
{
    if (window->mlx_img.data_addr || window->mlx_img.img_ptr)
        mlx_destroy_image(window->mlx_ptr, window->mlx_img.img_ptr);
    if (window->mlx_img.img_ptr)
        mlx_destroy_window(window->mlx_ptr, window->win_ptr);
    return (FALSE);
}

t_bool  init_window(t_window *window)
{
    window->mlx_ptr = mlx_init();
    window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, TITLE);
    if (window->win_ptr == NULL)
        return (FALSE);
    window->mlx_img.img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
    if (window->mlx_img.img_ptr == NULL)
        return (fail_to_window_init(window));
    window->mlx_img.data_addr = mlx_get_data_addr(window->mlx_img.img_ptr, \
                                                &window->mlx_img.bits_per_pixel, \
                                                &window->mlx_img.size_line, \
                                                &window->mlx_img.endian);
    if (window->mlx_img.data_addr == NULL)
        return (fail_to_window_init(window));
    hook_event(window);
    return (TRUE);
}
