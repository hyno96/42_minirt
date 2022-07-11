/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:56 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/11 20:31:43 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>

# include "structure.h"
# include "perror.h"
# include "libft.h"
# include "mlx_window.h"
# include "objects.h"
# include "parser.h"


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
    // parse rt file
    if (!parse_rt_file(argv[1], &data))
        return (ERR_PARSING);
    if (!init_window(&data.window))
    {
        ft_perror("failed to initiative mlx window");
        return (ERR_MLX_WIN);
    }
    // draw image
    mlx_put_image_to_window(data.window.mlx_ptr, data.window.win_ptr, \
                            data.window.mlx_img.img_ptr, 0, 0);
    mlx_loop(data.window.mlx_ptr);
}