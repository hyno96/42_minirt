/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:04:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 12:17:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "parser.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	index = 0;
	while (us1[index] && us2[index])
	{
		if (us1[index] != us2[index])
			return (us1[index] - us2[index]);
		index++;
	}
	return (us1[index] - us2[index]);
}

void	free_args(char **args)
{
	char	**temp;

	temp = args;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}

size_t	get_arg_num(char **args)
{
	size_t	arg_num;

	arg_num = 0;
	while (args[arg_num])
		arg_num++;
	return (arg_num);
}

t_bool	load_image(char *filename, t_img *image, t_data *data)
{
	image->img_ptr = mlx_xpm_file_to_image(\
		data->window.mlx_ptr, filename, &(image->x), &(image->y));
	if (image->img_ptr == 0)
		return (FALSE);
	image->data_addr = mlx_get_data_addr(image->img_ptr, \
			&(image->bits_per_pixel), &(image->size_line), &(image->endian));
	if (image->data_addr == 0)
		return (FALSE);
	return (TRUE);
}
