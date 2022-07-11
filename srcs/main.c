/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:56 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/09 15:16:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int main(int argc, char **argv)
{
    t_window    window;

    (void)argv;
    if (argc != 2)
    {
        ft_perror("usage: ./minirt filename.rt");
        return (ERR_ARGS);
    }
    if (!init_window(&window))
    {
        ft_perror("failed to initiative mlx window");
        return (ERR_MLX_WIN);
    }
    // parse rt file
    // draw image
    mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, \
                            window.mlx_img.img_ptr, WIDTH, HEIGHT);
    mlx_loop(window.mlx_ptr);
}