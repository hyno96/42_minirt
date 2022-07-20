/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_surf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:08:59 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 12:37:35 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "parser_bonus.h"
#include "libft.h"


t_bool	set_checker_board(char **args, t_surf *surf)
{
	if (args[1] && ft_strcmp(args[1], "\n") != 0)
		return (FALSE);
	surf->use_ctc = CTC_CHECKER;
	surf->checker.color1 = vec3(0.0, 0.0, 0.0);
	surf->checker.color2 = vec3(255.0, 255.0, 255.0);
	surf->checker.x_range = 1;
	surf->checker.y_range = 1;
	return (TRUE);
}

t_bool	set_bump_mapping(t_data *data, char *arg, t_surf *surf)
{
	char	**args;
	t_bool	result;
	char	**filename;

	args = ft_split(arg, ':');
	if (!args)
		return (FALSE);
	result = FALSE;
	if (ft_strcmp(args[0], "bumpmap") == 0 && get_arg_num(args) == 2)
	{
		filename = ft_split(args[1], '"');
		if (filename)
		{
			if (load_image(*filename, &(surf->bump_map), data))
			{
				result = TRUE;
				surf->use_bump_map = TRUE;
			}
			free_args(filename);
		}
	}
	free_args(args);
	return (result);
}

t_bool	set_texture(t_data *data, char *arg, t_surf *surf)
{
	char	**args;
	t_bool	result;
	size_t	arg_num;
	char	**filename;

	args = ft_split(arg, ':');
	if (!args)
		return (FALSE);
	result = FALSE;
	arg_num = get_arg_num(args);
	if (arg_num == 2)
	{
		if ((ft_strcmp(args[0], "texture") == 0))
		{
			filename = ft_split(args[1], '"');
			if (filename)
			{
				result = load_image(*filename, &(surf->texture), data);
				surf->use_ctc = CTC_TEXTURE;
				free_args(filename);
			}
		}
	}
	free_args(args);
	return (result);
}

t_bool	set_bonus_surf(char **args, t_surf *surf, t_data *data, \
						t_arg_num basic_arg_num)
{
	t_bool	result;
	char	**bonus_args;
	size_t	arg_num;

	bonus_args = ft_split(args[basic_arg_num], ':');
	if (!bonus_args)
		return (FALSE);
	arg_num = get_arg_num(args);
	if (arg_num > basic_arg_num)
	{
		if (ft_strcmp(bonus_args[0], "checker") == 0)
			result = set_checker_board(bonus_args, surf);
		else
			result = set_texture(data, args[basic_arg_num], surf);
	}
	if (arg_num == basic_arg_num + 2)
			result &= set_bump_mapping(data, args[basic_arg_num + 1], surf);
	free_args(bonus_args);
	return (result);
}

t_bool	tmp_set_bonus_surf(char **args, t_surf *surf, t_data *data, \
						t_arg_num basic_arg_num)
{
	t_bool	result;
	char	**bonus_args;
	size_t	arg_num;

	result = FALSE;
	bonus_args = ft_split(args[basic_arg_num], ':');
	if (!bonus_args)
		return (FALSE);
	arg_num = get_arg_num(args);
	if (arg_num > basic_arg_num)
	{
		if (ft_strcmp(bonus_args[0], "checker") == 0)
			result = set_checker_board(bonus_args, surf);
	}
	free_args(bonus_args);
	return (result);
}
