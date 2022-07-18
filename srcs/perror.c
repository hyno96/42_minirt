/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:45:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/18 14:20:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perror.h"

void	ft_perror(char *err_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
}
