/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:38:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 20:41:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERROR_H
# define PERROR_H

# include <stdlib.h>

# include "libft.h"

enum e_errno
{
	ERR_ARGS = 1,
	ERR_MLX_WIN = 2,
	ERR_PARSING = 3,
};

void	ft_perror(char *err_msg);

#endif