/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:59:41 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/21 15:59:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	algoritm(t_lemin *info)
{
	init_path(info);
	simple_moves(info);
	check_music(info);
	get_all_paths(info);
	moves(info);
}
