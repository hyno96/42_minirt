/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyno_main.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:52:36 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/25 22:52:38 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYNO_MAIN_H
# define HYNO_MAIN_H

# include "../includes/objects.h"

void	free_myarr(t_ray **ray_arr, t_color3 **screen);
void	set_orivec(t_list *head);
void	hyno_test(t_data data);

#endif