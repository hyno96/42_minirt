/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:04:33 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:06:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "parser_bonus.h"
#include "libft.h"

t_bool	str_to_vec3(char *arg, t_float vec3_args[3])
{
	char	**args;
	size_t	idx;
	t_bool	result;
	size_t	arg_num;

	result = TRUE;
	args = ft_split(arg, ',');
	if (args == NULL)
		return (FALSE);
	arg_num = get_arg_num(args);
	if (arg_num != 3)
		return (FALSE);
	idx = 0;
	while (idx < arg_num)
	{
		result &= str_to_float(args[idx], &(vec3_args[idx]));
		idx++;
	}
	free_args(args);
	return (result);
}
