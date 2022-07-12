/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:12:41 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/12 13:07:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perror.h"


void ft_perror(char *err_msg)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    ft_putendl_fd(err_msg, STDERR_FILENO);
}
