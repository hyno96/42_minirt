/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:54:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 09:55:37 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perror.h"

void	ft_perror(char *err_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
}
