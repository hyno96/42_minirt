/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:59:30 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 09:59:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>

# include "libft.h"
# include "structure.h"

# define BUFFER_SIZE 1024

char	*get_next_line(int fd);

#endif