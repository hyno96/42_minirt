/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:56 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/11 15:54:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int main(int argc, char **argv)
{
    t_data  data;

    (void)argv;
    if (argc != 2)
    {
        ft_perror("usage: ./minirt filename.rt");
        return (ERR_ARGS);
    }
    ft_memset((void *)&data, 0, sizeof(t_data));
    if (!init_window(&data.window))
    {
        ft_perror("failed to initiative mlx window");
        return (ERR_MLX_WIN);
    }
    // parse rt file
    // draw image
    mlx_put_image_to_window(data.window.mlx_ptr, data.window.win_ptr, \
                            data.window.mlx_img.img_ptr, 0, 0);
    mlx_loop(data.window.mlx_ptr);
}