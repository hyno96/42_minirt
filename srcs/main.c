/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:27:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/26 13:38:44 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "structure.h"
#include "perror.h"
#include "libft.h"
#include "mlx_window.h"
#include "objects.h"
#include "parser.h"
#include "hyno_main.h"

int	main(int argc, char **argv)
{
	t_data	data;

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
	if (!parse_rt_file(argv[1], &data))
		return (ERR_PARSING);
	hyno_test(data);
	mlx_loop(data.window.mlx_ptr);
}
