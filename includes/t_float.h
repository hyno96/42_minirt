/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_float.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:42:14 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 20:42:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FLOAT_H
# define T_FLOAT_H

# include <float.h>

# define FLOAT_MAX DBL_MAX
# define FLOAT_MIN (-FLOAT_MAX)

typedef double	t_float;

#endif